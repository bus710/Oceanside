using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using FTD2XX_NET;

namespace Sample01
{
    public class Program
    {
        FTDI.FT_STATUS ftStatus;
        FTDI FtdiDeviceHandler;
        UInt32 ftdiDeviceCount;
        bool openStatus;

        public void Open()
        {
            // Sample for FTDI's USB to serial cable.
            // Can be changed later when we have ST's USB feature.

            ftStatus = FTDI.FT_STATUS.FT_OK;
            FtdiDeviceHandler = new FTDI();

            ftStatus = FtdiDeviceHandler.GetNumberOfDevices(
                ref ftdiDeviceCount);

            if (ftStatus == FTDI.FT_STATUS.FT_OK)
            {
                Console.WriteLine("Num of devices: " + ftdiDeviceCount.ToString());
            }

            FTDI.FT_DEVICE_INFO_NODE[] ftdiDeviceList 
                = new FTDI.FT_DEVICE_INFO_NODE[ftdiDeviceCount];
            ftStatus = FtdiDeviceHandler.GetDeviceList(ftdiDeviceList);
            if(ftStatus == FTDI.FT_STATUS.FT_OK)
            {
                for(UInt32 i=0; i<ftdiDeviceCount; i++)
                {
                    Console.WriteLine("Device Index: " + i.ToString());
                    Console.WriteLine("Flags: " +
                                       String.Format("{0:x}", ftdiDeviceList[i].Flags));
                    Console.WriteLine("Type: " + ftdiDeviceList[i].Type.ToString());
                    Console.WriteLine("ID: " + String.Format("{0:x}", ftdiDeviceList[i].ID));
                    Console.WriteLine("Location ID: " + String.Format("{0:x}", ftdiDeviceList[i].LocId));
                    Console.WriteLine("Serial Number: " + ftdiDeviceList[i].SerialNumber.ToString());
                    Console.WriteLine("Description: " + ftdiDeviceList[i].Description.ToString());
                    Console.WriteLine("");
                }
            }

            ftStatus = FtdiDeviceHandler.OpenByIndex(0);
            FtdiDeviceHandler.GetSerialNumber(out string sn);
            Console.WriteLine(sn + "\n");

            if(ftStatus == FTDI.FT_STATUS.FT_OK)
            {
                FtdiDeviceHandler.SetBaudRate(115200);
                FtdiDeviceHandler.SetTimeouts(100, 100);
                openStatus = true;
            }
        }
        public void Close()
        {
            FtdiDeviceHandler.Close();
        }

        public static void Main(string[] args)
        {

            Program p = new Program();
            p.Open();
            if (p.openStatus == false){
                System.Environment.Exit(1);
            }

            UInt32 len1 = 0;
            UInt32 len2 = 0;

            while (true)
            {
                Thread.Sleep(1000);

                byte[] data = new Byte[128000];
                p.FtdiDeviceHandler.GetRxBytesAvailable(ref len1);
                p.FtdiDeviceHandler.Read(data, len1, ref len2);
                Console.WriteLine(">> " + len2);

                UInt32 loc;
                for(loc=0; loc<128; loc++)
                {
                    if ((data[loc] == 0xaa) && (data[loc+1] == 0xaa))
                    {
                        for(int i=0; i<17; i++)
                        {
                            Console.Write(data[loc + i] + " ");
                        }
                        Console.WriteLine();
                        break;
                    }
                }
                //Console.ReadKey();
                Console.WriteLine();
            }
            p.Close();
        }


    }
}
