namespace Sample02_winform
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.Label01_device = new System.Windows.Forms.Label();
            this.ListBox01_comport = new System.Windows.Forms.ListBox();
            this.Button01_scan = new System.Windows.Forms.Button();
            this.Label99_device_status = new System.Windows.Forms.Label();
            this.Button02_open = new System.Windows.Forms.Button();
            this.Button03_close = new System.Windows.Forms.Button();
            this.Label_f003 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Label01_device
            // 
            this.Label01_device.AutoSize = true;
            this.Label01_device.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Label01_device.Location = new System.Drawing.Point(13, 13);
            this.Label01_device.Name = "Label01_device";
            this.Label01_device.Size = new System.Drawing.Size(112, 20);
            this.Label01_device.TabIndex = 0;
            this.Label01_device.Text = "Device Setting";
            // 
            // ListBox01_comport
            // 
            this.ListBox01_comport.FormattingEnabled = true;
            this.ListBox01_comport.ItemHeight = 12;
            this.ListBox01_comport.Location = new System.Drawing.Point(17, 46);
            this.ListBox01_comport.Name = "ListBox01_comport";
            this.ListBox01_comport.Size = new System.Drawing.Size(152, 88);
            this.ListBox01_comport.TabIndex = 1;
            // 
            // Button01_scan
            // 
            this.Button01_scan.Location = new System.Drawing.Point(185, 46);
            this.Button01_scan.Name = "Button01_scan";
            this.Button01_scan.Size = new System.Drawing.Size(75, 23);
            this.Button01_scan.TabIndex = 2;
            this.Button01_scan.Text = "Scan";
            this.Button01_scan.UseVisualStyleBackColor = true;
            this.Button01_scan.Click += new System.EventHandler(this.Button01_scan_Click_1);
            // 
            // Label99_device_status
            // 
            this.Label99_device_status.AutoSize = true;
            this.Label99_device_status.Location = new System.Drawing.Point(194, 19);
            this.Label99_device_status.Name = "Label99_device_status";
            this.Label99_device_status.Size = new System.Drawing.Size(45, 12);
            this.Label99_device_status.TabIndex = 3;
            this.Label99_device_status.Text = "Closed";
            // 
            // Button02_open
            // 
            this.Button02_open.Location = new System.Drawing.Point(185, 76);
            this.Button02_open.Name = "Button02_open";
            this.Button02_open.Size = new System.Drawing.Size(75, 23);
            this.Button02_open.TabIndex = 4;
            this.Button02_open.Text = "Open";
            this.Button02_open.UseVisualStyleBackColor = true;
            this.Button02_open.Click += new System.EventHandler(this.Button02_open_Click_1);
            // 
            // Button03_close
            // 
            this.Button03_close.Location = new System.Drawing.Point(185, 106);
            this.Button03_close.Name = "Button03_close";
            this.Button03_close.Size = new System.Drawing.Size(75, 23);
            this.Button03_close.TabIndex = 5;
            this.Button03_close.Text = "Close";
            this.Button03_close.UseVisualStyleBackColor = true;
            this.Button03_close.Click += new System.EventHandler(this.Button03_close_Click_1);
            // 
            // Label_f003
            // 
            this.Label_f003.AutoSize = true;
            this.Label_f003.Location = new System.Drawing.Point(40, 199);
            this.Label_f003.Name = "Label_f003";
            this.Label_f003.Size = new System.Drawing.Size(30, 12);
            this.Label_f003.TabIndex = 6;
            this.Label_f003.Text = "f003:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(497, 529);
            this.Controls.Add(this.Label_f003);
            this.Controls.Add(this.Button03_close);
            this.Controls.Add(this.Button02_open);
            this.Controls.Add(this.Label99_device_status);
            this.Controls.Add(this.Button01_scan);
            this.Controls.Add(this.ListBox01_comport);
            this.Controls.Add(this.Label01_device);
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Project Oceanside";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Label01_device;
        private System.Windows.Forms.ListBox ListBox01_comport;
        private System.Windows.Forms.Button Button01_scan;
        private System.Windows.Forms.Label Label99_device_status;
        private System.Windows.Forms.Button Button02_open;
        private System.Windows.Forms.Button Button03_close;
        private System.Windows.Forms.Label Label_f003;
    }
}

