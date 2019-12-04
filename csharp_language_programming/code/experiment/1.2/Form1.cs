using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1._2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Application.Exit();
        }

        int deltX = 10;
        int deltY = 8;
        int colorX = 125;
        int colorY = 225;
        int colorZ = 0;

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.label1.Left += deltX;
            this.label1.Top += deltY;
            if (this.label1.Left < 0 || this.label1.Left + this.label1.Width > this.Width)
                deltX = -deltX;
            if (this.label1.Top < 0 || this.label1.Top + this.label1.Height > this.Height)
                deltY = -deltY;
        }

    }
}
