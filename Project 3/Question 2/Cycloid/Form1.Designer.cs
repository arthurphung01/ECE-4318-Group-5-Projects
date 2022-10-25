using System.Windows.Forms;

using System.Drawing;
using System.Threading;


namespace Cycloid
{
    partial class Form1
    {
        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox t1;
        private TextBox t2;
        private TextBox t3;
        private TextBox t5;
        private TextBox t4;
        private Label label4;
        private Label label5;
        private Label label9;
        private Label label10;
        private ComboBox c1;
        private ComboBox c2;
        private ComboBox c3;
        private Label label11;
        private Button b1;
        System.Drawing.SolidBrush drawBrush = new System.Drawing.SolidBrush(System.Drawing.Color.Green);
        System.Drawing.Pen myPen = new System.Drawing.Pen(System.Drawing.Color.Red);
   
        private int a = 100, b = 100; // Where the big circle starts
        private int r = 50; // the radius of the big circle
        private int sr = 2; // the radius of small circle
        private int speed = 20;
        public const double PI = 3.14159265358979323846;
        private bool painting = false;
        private int length = 100;
        private string lineColor = "Blue";
        private string circleColor = "Red";
        private string smallCircleColor = "Green";
        private double thetainit = 0.0;
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.t1 = new System.Windows.Forms.TextBox();
            this.t2 = new System.Windows.Forms.TextBox();
            this.t3 = new System.Windows.Forms.TextBox();
            this.t5 = new System.Windows.Forms.TextBox();
            this.t4 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.c1 = new System.Windows.Forms.ComboBox();
            this.c2 = new System.Windows.Forms.ComboBox();
            this.c3 = new System.Windows.Forms.ComboBox();
            this.label11 = new System.Windows.Forms.Label();
            this.b1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(46, 290);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Circle Size";
            this.label1.UseMnemonic = false;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 316);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(84, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Small Circle Size";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(4, 342);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(98, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Starting Offset (rad)";
            // 
            // t1
            // 
            this.t1.Location = new System.Drawing.Point(108, 290);
            this.t1.Name = "t1";
            this.t1.Size = new System.Drawing.Size(100, 20);
            this.t1.TabIndex = 3;
            // 
            // t2
            // 
            this.t2.Location = new System.Drawing.Point(108, 316);
            this.t2.Name = "t2";
            this.t2.Size = new System.Drawing.Size(100, 20);
            this.t2.TabIndex = 4;
            // 
            // t3
            // 
            this.t3.Location = new System.Drawing.Point(108, 342);
            this.t3.Name = "t3";
            this.t3.Size = new System.Drawing.Size(100, 20);
            this.t3.TabIndex = 5;
            // 
            // t5
            // 
            this.t5.Location = new System.Drawing.Point(305, 290);
            this.t5.Name = "t5";
            this.t5.Size = new System.Drawing.Size(100, 20);
            this.t5.TabIndex = 9;
            // 
            // t4
            // 
            this.t4.Location = new System.Drawing.Point(108, 368);
            this.t4.Name = "t4";
            this.t4.Size = new System.Drawing.Size(100, 20);
            this.t4.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(232, 290);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(67, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Circle Speed";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label5.Location = new System.Drawing.Point(46, 368);
            this.label5.Name = "label5";
            this.label5.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label5.Size = new System.Drawing.Size(52, 13);
            this.label5.TabIndex = 6;
            this.label5.Text = "Rotations";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(211, 343);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(88, 13);
            this.label9.TabIndex = 17;
            this.label9.Text = "Small Circle Color";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(239, 316);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(60, 13);
            this.label10.TabIndex = 16;
            this.label10.Text = "Circle Color";
            // 
            // c1
            // 
            this.c1.FormattingEnabled = true;
            this.c1.Items.AddRange(new object[] {
            "Red",
            "Orange",
            "Yellow",
            "Green",
            "Blue",
            "Purple",
            "White",
            "Black"});
            this.c1.Location = new System.Drawing.Point(305, 316);
            this.c1.Name = "c1";
            this.c1.Size = new System.Drawing.Size(121, 21);
            this.c1.TabIndex = 18;
            // 
            // c2
            // 
            this.c2.FormattingEnabled = true;
            this.c2.Items.AddRange(new object[] {
            "Red",
            "Orange",
            "Yellow",
            "Green",
            "Blue",
            "Purple",
            "White",
            "Black"});
            this.c2.Location = new System.Drawing.Point(305, 343);
            this.c2.Name = "c2";
            this.c2.Size = new System.Drawing.Size(121, 21);
            this.c2.TabIndex = 19;
            // 
            // c3
            // 
            this.c3.FormattingEnabled = true;
            this.c3.Items.AddRange(new object[] {
            "Red",
            "Orange",
            "Yellow",
            "Green",
            "Blue",
            "Purple",
            "White",
            "Black"});
            this.c3.Location = new System.Drawing.Point(305, 370);
            this.c3.Name = "c3";
            this.c3.Size = new System.Drawing.Size(121, 21);
            this.c3.TabIndex = 20;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(245, 370);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(54, 13);
            this.label11.TabIndex = 21;
            this.label11.Text = "Line Color";
            // 
            // b1
            // 
            this.b1.Location = new System.Drawing.Point(447, 290);
            this.b1.Name = "b1";
            this.b1.Size = new System.Drawing.Size(75, 23);
            this.b1.TabIndex = 22;
            this.b1.Text = "Draw Circle";
            this.b1.UseVisualStyleBackColor = true;
            this.b1.Click += new System.EventHandler(this.b1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1334, 411);
            this.Controls.Add(this.b1);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.c3);
            this.Controls.Add(this.c2);
            this.Controls.Add(this.c1);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.t5);
            this.Controls.Add(this.t4);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.t3);
            this.Controls.Add(this.t2);
            this.Controls.Add(this.t1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        protected override void OnPaint(PaintEventArgs e)
        {

            if (!painting)
            {
                return;
            }
            //   System.Drawing.Pen myPen;
            //   myPen = new System.Drawing.Pen(System.Drawing.Color.Red);

            System.Drawing.Graphics formGraphics = CreateGraphics();

            myPen.Color = System.Drawing.Color.FromArgb(240, 240, 240);
            SolidBrush grayBrush = new SolidBrush(Color.FromArgb(240, 240, 240));
            formGraphics.FillRectangle(grayBrush, 0, 0, 1450, 500);

            //
            // 	System.out.println ("Cycloid started now");

            myPen.Color = System.Drawing.Color.FromName(lineColor);
            // formGraphics.setColor (Color.blue); // the color of the line
            // where the big circle rolls

            formGraphics.DrawLine(myPen, a - 20, b + r + 1, a + 1350, b + r + 1);
    	    //	g.drawLine(a-20, b - r - 1, a + 1000, b - r - 1);
    		double theta, thetachange;
    	  
    	    theta = thetainit;
    	    thetachange = PI/20;
    	        
            myPen.Color = System.Drawing.Color.FromName(smallCircleColor);

            for (int i = 0; i < length; i = i + 1) {
    	         //   Color backgroundColour = getBackground();
                    Color backgroundColour = Form1.DefaultBackColor;
    	       
                     myPen.Color = backgroundColour;
                     drawBigCircle(theta, formGraphics);
    	               	          	      
    	             theta = theta + thetachange;
    	            
                     myPen.Color = System.Drawing.Color.FromName(circleColor);

                     drawBigCircle(theta, formGraphics);    
	                 myPen.Color = System.Drawing.Color.FromName(smallCircleColor);

                     drawSmallCircle(theta, formGraphics);
              ///      
                     Font drawFont = new Font("Arial", 16);
                  
                     Thread.Sleep(speed);
    	            
    	        }  // end of for loop

          
            // myPen.Dispose();
            formGraphics.Dispose();
            painting = false;
        }  // end of OnPaint

        public void drawBigCircle(double theta, Graphics formGraphics)
        {
            // Center of big circle is (a + r * theta, b)
            // Center of small solid circle is  x = a + r* theta + r * sin (theta)
            // y = b - r * cos (theta)
            //    		double theta = (i* (Math.PI)/180);
            double bx, by; // center of big circle
            double sx, sy; // center of small circle

            bx = a + r * theta;
            by = b;

            //    			sx = a + r * theta + r * Math.sin(theta);
            //  			sy = b - r * Math.cos (theta);

            formGraphics.DrawEllipse (myPen, (int)bx - r, (int)by - r, 2 * r, 2 * r);

            //          Draw small circle

            //    	    g.setColor(Color.red);
            //    	    g.fillOval ((int) sx - sr, (int) sy - sr, 2 * sr, 2 * sr);

        }  // end of drawBigCircle

        public void drawSmallCircle(double theta, Graphics formGraphics)
        {
            // Center of big circle is (a + r * theta, b)
            // Center of small solid circle is  x = a + r* theta + r * sin (theta)
            // y = b - r * cos (theta)
            //    		double theta = (i* (Math.PI)/180);
            //   		double bx, by; // center of big circle
            double sx, sy; // center of small circle

            sx = a + r * theta + r * System.Math.Sin(theta);
            sy = b - r * System.Math.Cos(theta);

            //          Draw small circle
            drawBrush.Color = Color.FromName(smallCircleColor);
            //    	    g.setColor(Color.red);
            formGraphics.FillEllipse(drawBrush, (int)sx - sr, (int)sy - sr, 2 * sr, 2 * sr);

        }  // end of drawBigCircle
    }
}

