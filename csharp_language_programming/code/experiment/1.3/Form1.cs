using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1._3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        int a, b;
        string op;
        int result;

        Random rnd = new Random();

        private void btnJudge_Click(object sender, EventArgs e)
        {
            string answer = txtAnswer.Text;
            double d = double.Parse(answer);
            string disp = "" + a + op + b + "=" + answer + " ";
            if (Math.Abs(d - result) < 1e-3)
                disp += "√";
            else
                disp += "×";
            lstDisp.Items.Add(disp);

        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            a = rnd.Next(9) + 1;
            b = rnd.Next(9) + 1;
            int w = rnd.Next(4);
            switch(w)
            {
                case 0:op = "+";result = a + b;break;
                case 1:op = "-";result = a - b;break;
                case 2:op = "*";result = a * b;break;
                case 3:op = "/";result = a / b;break;
            }
            this.labA.Text = a.ToString();
            this.labB.Text = b.ToString();
            this.labOP.Text = op;
            this.txtAnswer.Text = ""; 
        }
    }
}
