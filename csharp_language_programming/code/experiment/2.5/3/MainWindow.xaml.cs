using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;

namespace _3
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private bool _save = true;
        private string str = "";

        private void NewCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            if (_save)
            {
                txtEdit.Text = "";
                MessageBox.Show("New");
                str = txtEdit.Text;
                _save = true;
            }
            else
                MessageBox.Show("该文本还未保存，请先进行保存操作！");
        }

        private void OpenCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            if (_save)
            {
                OpenFileDialog dlg = new OpenFileDialog();
                dlg.DefaultExt = "*.txt";
                dlg.Filter = "Text Files (*.txt)|*.txt";
                bool? result = dlg.ShowDialog();
                if (result == true)
                {
                    string fileName = dlg.FileName;
                    StreamReader dd = new StreamReader(fileName);
                    txtEdit.Text = dd.ReadToEnd();
                    dd.Close();
                    MessageBox.Show("Open");
                    str = txtEdit.Text;
                    _save = true;
                }
            }
            else
                MessageBox.Show("该文本还未保存，请先进行保存操作！");
        }

        private void SaveCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "文本文件|*.txt|所有文件|*.*";
            saveFileDialog.FilterIndex = 0;
            bool? result = saveFileDialog.ShowDialog();
            if (result == true)
            {
                string strFile = saveFileDialog.FileName;
                StreamWriter ss = new StreamWriter(strFile);
                ss.WriteLine(txtEdit.Text);
                ss.Close();
                MessageBox.Show("Save");
                str = txtEdit.Text;
                _save = true;
            }
        }

        private void txtEdit_TextChanged(object sender, TextChangedEventArgs e)
        {
            if (str != txtEdit.Text)
                _save = false;
        }
    }
}
