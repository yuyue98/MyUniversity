using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1._7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        const int N = 4;//按钮行列数
        Button[,] buttons = new Button [ N, N ];

        private void button1_Click(object sender, EventArgs e)
        {
            //打乱顺序
            shuffle();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //产生所有按钮
            getallbutton();
        }

        Random rnd = new Random(); 

        void shuffle()
        {
            for (int i = 0; i < 100;i++)
            {
                int a = rnd.Next(N);
                int b = rnd.Next(N);
                int c = rnd.Next(N);
                int d = rnd.Next(N);
                swap(buttons[a, b], buttons[c, d]);
            }
        }

        void swap(Button btnA,Button btnB)
        {
            string s = btnA.Text;
            btnA.Text = btnB.Text;
            btnB.Text = s;
            bool v = btnA.Visible;
            btnA.Visible = btnB.Visible;
            btnB.Visible = v;
        }

        void getallbutton()
        {
            int w = 45, d = 50;
            int x0 = this.Width / 2 - N * d / 2;
            int y0 = this.Height / 2 - N * d / 2 - d;
            for (int i = 0;i < N;i++)
            {
                for (int j = 0;j < N;j++)
                {
                    int num = i * N + j;
                    Button btn = new Button();
                    btn.Text = (num + 1).ToString();
                    btn.Left = x0 + j * d;
                    btn.Top = y0 + i * d;
                    btn.Width = w;
                    btn.Height = w;
                    btn.Visible = true;
                    btn.Tag = num;
                    //注册事件
                    btn.Click += new EventHandler(btn_click);
                    buttons[i, j] = btn;
                    this.Controls.Add(btn);
                }
            }
            buttons[N - 1, N - 1].Visible = false;
        }

        void btn_click(object sender,EventArgs e)
        {
            Button btn = sender as Button;
            Button blank = findblankbutton();//空白按钮

            //判断是否与空白快相邻，如果是，交换
            if (isnearblank(btn,blank))
            {
                swap(btn, blank);
                blank.Focus();
            }

            //判断是否完成游戏
            if(istrueresult())
            {
                MessageBox.Show("OK!");
            }
        }

        //寻找隐藏按钮
        Button findblankbutton()
        {
            for (int i = 0;i < N;i++)
            {
                for (int j = 0; j < N;j++)
                {
                    if (!buttons[i, j].Visible)
                        return buttons[i, j];
                }
            }
            return null;
        }

        //判断是否与空白块相邻
        bool isnearblank(Button btnA, Button btnB)
        {
            int a = (int)btnA.Tag;
            int b = (int)btnB.Tag;
            int i1 = a / N, j1 = a % N;
            int i2 = b / N, j2 = b % N;
            if ((i1 == i2 && (j1 == j2 - 1 || j1 == j2 + 1))
            || (j1 == j2 && (i1 == i2 - 1 || i1 == i2 + 1)))
                return true;
            return false;
        }

        bool istrueresult()
        {
            for (int i = 0;i < N;i++)
            {
                for (int j = 0;j < N;j++)
                {
                    if (buttons[i, j].Text != (i * N + j + 1).ToString())
                        return false;
                }
            }
            return true;
        }
    }
}
