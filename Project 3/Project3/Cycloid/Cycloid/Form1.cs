using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Cycloid
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            t1.Text = "50";
            t2.Text = "2";
            t3.Text = "0.0";
            t4.Text = "2.5";
            t5.Text = "20";
            c1.Text = "Red";
            c2.Text = "Green";
            c3.Text = "Blue";
        }

        private void b1_Click(object sender, EventArgs e)
        {
            int csz = Convert.ToInt32(t1.Text);
            int scs = Convert.ToInt32(t2.Text);
            double sp = Convert.ToDouble(t3.Text);
            double ep = Convert.ToDouble(t4.Text);
            int csp = Convert.ToInt32(t5.Text);
            String cc = c1.Text;
            String scc = c2.Text;
            String lc = c3.Text;
            r = csz;
            sr = scs;
            thetainit = sp;
            b = 200;
            speed = csp;
            length = (int) (ep * 40);
            lineColor = lc;
            circleColor = cc;
            smallCircleColor = scc;
            painting = true;
        }
    }
}
