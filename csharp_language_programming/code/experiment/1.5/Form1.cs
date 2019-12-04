using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1._5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Random rnd = new Random();
        
        Color getrndcolor()
        {
            return Color.FromArgb(
                rnd.Next(256),
                rnd.Next(256),
                rnd.Next(256)
            );
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            int x0 = this.Width / 2;
            int y0 = this.Height / 2;
            for (int i = 0;i < this.Width/2;i++)
            {
                g.DrawEllipse(
                    new Pen(getrndcolor(), 1),
                    x0 - i, y0 - i, i * 2, i * 2
                    );
            }
        }

        int deltX = 10;
        int deltY = 8;
        int num = 0;

        private void timer1_Tick(object sender, EventArgs e)
        {
            Graphics g = this.CreateGraphics();
            int x0 = rnd.Next(this.Width) + 1;
            int y0 = rnd.Next(this.Height) + 1;
            int i = 50;
            if (x0 + i < this.Width && y0 + i < this.Height)
            g.DrawEllipse(
                    new Pen(getrndcolor(), 1),
                    x0, y0, i, i
                    );
            num++;
            if (num > 100)
            {
                this.ForeColor = getrndcolor();
                num = 0;
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.ForeColor = getrndcolor();
        }

    }
}
