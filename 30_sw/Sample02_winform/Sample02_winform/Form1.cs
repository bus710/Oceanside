using System;
using System.Collections.Generic;

using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;

using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Threading.Tasks;

using System.Threading;
using System.Windows.Forms;
using FTD2XX_NET;

namespace Sample02_winform
{
    public partial class Form1 : Form
    {
        private static FTDI.FT_STATUS ftStatus;
        private static FTDI currentFtdiDevice;
        private static FTDI.FT_DEVICE_INFO_NODE[] ftdiDeviceList;
        private static List<Dictionary<string, string>> deviceList
            = new List<Dictionary<string, string>>();
        private static UInt32 ftdiDeviceCount = 0;

        private static int selectedIndex = 0;
        private static uint isOpened = 0;

        private static Dictionary<string, string> commandString
             = new Dictionary<string, string>();
        private static Dictionary<string, int> commandLength
            = new Dictionary<string, int>();

        Thread serialReaderThreadRef;
        Thread tcpServerThreadRef;

        TcpListener server = null;

        uint cnt = 0;

        public Form1()
        {
            InitializeComponent();
            currentFtdiDevice = new FTDI();

            GetFtdiDevNum();
            GetInfoFromFtdi();
        }

        private void GetFtdiDevNum()
        {
            ftStatus = currentFtdiDevice.GetNumberOfDevices(ref ftdiDeviceCount);
            if (ftStatus == FTDI.FT_STATUS.FT_OK)
            {
                Console.WriteLine("Number of FTDI devices: " + ftdiDeviceCount.ToString());
                Console.WriteLine("");
            }
            else
            {
                Console.WriteLine("Failed to get number of devices (error " + ftStatus.ToString() + ")");
                Console.ReadKey();
                ftdiDeviceCount = 0;
            }
        }

        private void GetInfoFromFtdi()
        {
            // check the information of available ftdi device.

            ftdiDeviceList = new FTDI.FT_DEVICE_INFO_NODE[ftdiDeviceCount];

            ftStatus = currentFtdiDevice.GetDeviceList(ftdiDeviceList);

            if (ftStatus == FTDI.FT_STATUS.FT_OK)
            {
                ListBox01_comport.Items.Clear();

                for (UInt32 i = 0; i < ftdiDeviceCount; i++)
                {
                    Dictionary<string, string> dd = new Dictionary<string, string>
                    {
                        { "index", i.ToString() },
                        { "flag", String.Format("{0:x}", ftdiDeviceList[i].Flags) },
                        { "type", ftdiDeviceList[i].Type.ToString() },
                        { "id", String.Format("{0:x}", ftdiDeviceList[i].ID) },
                        { "location", String.Format("{0:x}", ftdiDeviceList[i].LocId) },
                        { "serial", ftdiDeviceList[i].SerialNumber.ToString() },
                        { "description", ftdiDeviceList[i].Description.ToString() }
                    };
                    deviceList.Add(dd);
                    //dd.Clear();

                    Console.WriteLine("Index: " + i.ToString());
                    Console.WriteLine("Flags: " + String.Format("{0:x}", ftdiDeviceList[i].Flags));
                    Console.WriteLine("Type: " + ftdiDeviceList[i].Type.ToString());
                    Console.WriteLine("ID: " + String.Format("{0:x}", ftdiDeviceList[i].ID));
                    Console.WriteLine("Location ID: " + String.Format("{0:x}", ftdiDeviceList[i].LocId));
                    Console.WriteLine("Serial Number: " + ftdiDeviceList[i].SerialNumber.ToString());
                    Console.WriteLine("Description: " + ftdiDeviceList[i].Description.ToString());
                    Console.WriteLine("");

                    ListBox01_comport.Items.Add(ftdiDeviceList[i].SerialNumber.ToString());
                }
            }
        }

        private int OpenFtdiDevice()
        {
            // open an ftdi device.

            var ftdiDevice = ftdiDeviceList[selectedIndex];

            if (ftdiDevice.SerialNumber == "")
            {
                return -1;
            }

            ftStatus = currentFtdiDevice.OpenBySerialNumber(ftdiDevice.SerialNumber);

            ftStatus = currentFtdiDevice.SetBaudRate(115200);
            if (ftStatus != FTDI.FT_STATUS.FT_OK)
            {
                Console.WriteLine("Failed to set Baud rate (error " + ftStatus.ToString() + ")");
                Console.ReadKey();
                return -1;
            }

            ftStatus = currentFtdiDevice.SetDataCharacteristics(FTDI.FT_DATA_BITS.FT_BITS_8,
                                                           FTDI.FT_STOP_BITS.FT_STOP_BITS_1,
                                                           FTDI.FT_PARITY.FT_PARITY_NONE);
            if (ftStatus != FTDI.FT_STATUS.FT_OK)
            {
                Console.WriteLine("Failed to set data characteristics (error " + ftStatus.ToString() + ")");
                Console.ReadKey();
                return -1;
            }

            ftStatus = currentFtdiDevice.SetFlowControl(FTDI.FT_FLOW_CONTROL.FT_FLOW_NONE, 0x11, 0x13);
            if (ftStatus != FTDI.FT_STATUS.FT_OK)
            {
                Console.WriteLine("Failed to set flow control (error " + ftStatus.ToString() + ")");
                Console.ReadKey();
                return -1;
            }

            ftStatus = currentFtdiDevice.SetTimeouts(300, 300);
            if (ftStatus != FTDI.FT_STATUS.FT_OK)
            {
                Console.WriteLine("Failed to set timeouts (error " + ftStatus.ToString() + ")");
                Console.ReadKey();
                return -1;
            }

            isOpened = 1;

            return 0;
        }

        private void CloseFtdiDevice()
        {
            ftStatus = currentFtdiDevice.Close();
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            Console.WriteLine("Loading...");
            currentFtdiDevice = new FTDI();
        }

        private void Button01_scan_Click_1(object sender, EventArgs e)
        {
            GetFtdiDevNum();
            GetInfoFromFtdi();
        }

        private void Button02_open_Click_1(object sender, EventArgs e)
        {
            selectedIndex = ListBox01_comport.SelectedIndex;
            if ((selectedIndex >= 0) && (isOpened == 0))
            {
                if (OpenFtdiDevice() > -1)
                {
                    Console.WriteLine("Opened.");
                    Label99_device_status.Text = "Opened";
                    Label99_device_status.Refresh();

                    serialReaderThreadRef = new Thread(SerialReader);
                    serialReaderThreadRef.Start();
                    tcpServerThreadRef = new Thread(TcpServer);
                    tcpServerThreadRef.Start();
                }
                else
                {
                    Console.WriteLine("Error.");
                }
            }
        }

        private void Button03_close_Click_1(object sender, EventArgs e)
        {
            if ((selectedIndex >= 0) && (isOpened == 1))
            {
                isOpened = 0;

                CloseFtdiDevice();
                serialReaderThreadRef.Join();
                server.Stop();
                tcpServerThreadRef.Join();

                Console.WriteLine("Closed.");
                Label99_device_status.Text = "Closed";
                Label99_device_status.Refresh();
            }
        }

        private void SerialReader()
        {
            Console.WriteLine("serial reader thread started.");
            while (true)
            {
                Thread.Sleep(1000);

                if (isOpened == 0)
                {
                    break;
                }

                uint len1 = 0;
                uint len2 = 0;
                byte[] data = new Byte[5120];   // 4096 + 25%
                byte[,] buf = new Byte[256, 16]; // 4096

                currentFtdiDevice.GetRxBytesAvailable(ref len1);
                currentFtdiDevice.Read(data, len1, ref len2);
                Console.WriteLine(">> " + len2);


                // A loop to copy serial data to 2d array.
                UInt32 loc;
                UInt32 addr = 0;
                for (loc = 0; loc < len2-2; loc++)
                {
                    if ((data[loc] == 0xaa) && (data[loc + 1] == 0xaa))
                    {
                        addr = data[loc + 2];
                        for (uint i = loc; i < loc + 16; i++)
                        {
                            //Console.Write(data[loc + i] + " ");
                            if((addr < 256) && (i<len2))
                            {
                                buf[addr, i - loc] = data[i];
                            }
                        }
                        //Console.WriteLine();
                        loc += 15;
                    }

                }

                // Checking f003.
                cnt = 0;
                for (uint j = 0; j < 256; j++)
                {
                    if ((buf[j, 5] == 240) && (buf[j,6] == 3))
                    {
                        cnt += 1;
                    }
/*
                    for (uint i = 0; i < 16; i++)
                    {
                        Console.Write(buf[j, i] + " ");
                    }
                    Console.WriteLine();
                    */
                }
                Console.WriteLine(cnt);

            }
        }

        private void TcpServer()
        {
            Console.WriteLine("tcp server thread started.");

            try
            {
                Int32 port = 8081;
                IPAddress localAddr = IPAddress.Parse("127.0.0.1");
                server = new TcpListener(localAddr, port);

                server.Start();

                while (true) {
                    TcpClient client = server.AcceptTcpClient();
                    Console.WriteLine("Connection requested.");

                    NetworkStream stream = client.GetStream();

                    while (isOpened == 1)
                    {
                        byte[] msg = System.Text.Encoding.ASCII.GetBytes(cnt.ToString());
                        stream.Write(msg, 0, msg.Length);
                        //Console.WriteLine("len: " + msg.Length);
                        Thread.Sleep(1000);
                    }
                    client.Close();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine();
                Console.WriteLine("Exception: {0}", e);
            }
            finally
            {
                server.Stop();
            }

        }

    } // class
} // namespace
