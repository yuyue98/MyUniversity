using System;
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

namespace _4
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public Dictionary<string, string[]> changes = new Dictionary<string, string[]>();
        public Dictionary<string, string> flog = new Dictionary<string, string>();
        public Dictionary<string, double> aggregate = new Dictionary<string, double>();
        public MainWindow()
        {
            string[] str1 = { "km(公里)", "m(米)", "cm(厘米)", "mm(毫米)", "mile(英里)", "ft(英尺)", "in(英寸)" };
            string[] str2 = { "t(吨)", "kg(千克)", "g(克)", "mg(毫克)", "jin（斤）", "lb(磅)", "ct(克拉)" };
            string[] str3 = { "K(开氏度)", "℃(摄氏度)", "℉(华氏度)" };
            changes.Add("长度", str1);
            changes.Add("重量", str2);
            changes.Add("温度", str3);
            flog.Add("长度", "L");
            flog.Add("重量", "W");
            flog.Add("温度", "T");
            aggregate.Add("km(公里)", 1000);
            aggregate.Add("m(米)", 1);
            aggregate.Add("cm(厘米)", 0.01);
            aggregate.Add("mm(毫米)", 0.001);
            aggregate.Add("mile(英里)", 1609.344);
            aggregate.Add("ft(英尺)", 0.3048);
            aggregate.Add("in(英寸)", 0.0254);
            aggregate.Add("t(吨)", 1000000);
            aggregate.Add("kg(千克)", 1000);
            aggregate.Add("g(克)", 1);
            aggregate.Add("mg(毫克)", 0.001);
            aggregate.Add("jin（斤）", 500);
            aggregate.Add("lb(磅)", 453.59237);
            aggregate.Add("ct(克拉)", 0.2);
            InitializeComponent();
        }

        private double Tp(double data, string lvt1, string lvt2)
        {
            if (lvt1 != lvt2)
            {
                if (lvt1 == "K(开氏度)")
                {
                    data += 273;
                    if (lvt2 == "℉(华氏度)")
                        data = data * 9.0 / 4 + 32;
                }
                else if (lvt1 == "℃(摄氏度)")
                {
                    if (lvt2 == "K(开氏度)")
                        data -= 273;
                    else if (lvt2 == "℉(华氏度)")
                        data = data * 9.0 / 5 + 32;
                }
                else if (lvt1 == "℉(华氏度)")
                {
                    data = (data - 32) * 5.0 / 9;
                    if (lvt2 == "℃(摄氏度)")
                        data -= 273;
                }
            }
            return data;
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                listvist1.Items.Clear();
                listvist2.Items.Clear();
                ComboBox cb = sender as ComboBox;
                ComboBoxItem cbitem = cb.SelectedItem as ComboBoxItem;
                string selected = cbitem.Content.ToString();
                string[] vs = changes[selected];
                for (int i = 0; i < vs.Length; i++)
                {
                    listvist1.Items.Add(vs[i]);
                    listvist2.Items.Add(vs[i]);
                }
            }
            catch (KeyNotFoundException x)
            {
                Console.WriteLine(x.ToString());
            }
        }

        private void change(object sender, RoutedEventArgs e)
        {
            try
            {
                string text = textbox1.Text;
                double data = Convert.ToDouble(text);
                string lvt1 = listvist1.SelectedItem.ToString();
                string lvt2 = listvist2.SelectedItem.ToString();
                double result = 0;
                if (combobox1.Text != "温度")
                    result = data * (aggregate[lvt1] / aggregate[lvt2]);
                else
                    result = Tp(data, lvt1, lvt2);
                label7.Content = lvt1;
                label8.Content = lvt2;
                label3.Content = result.ToString();
                
            }
            catch (FormatException x)
            {
                string str = x + ":" + "原始数据格式有误！";
                MessageBox.Show(str);
                //label3.Content = x + " : " + "原始数据格式有误！";
            }
            catch (NullReferenceException y)
            {
                string str = y + ":" + "原始数据格式有误！";
                MessageBox.Show(str);
                //label3.Content = y + " : " + "没有选择单位！";
            }
            catch 
            {
                string str ="NULL";
                MessageBox.Show(str);
            }
        }

        private void comboboxitem1_Selected(object sender, RoutedEventArgs e)
        {
            label6.Content = flog[comboboxitem1.Content.ToString()];
        }

        private void comboboxitem2_Selected(object sender, RoutedEventArgs e)
        {
            label6.Content = flog[comboboxitem2.Content.ToString()];
        }

        private void comboboxitem3_Selected(object sender, RoutedEventArgs e)
        {
            label6.Content = flog[comboboxitem3.Content.ToString()];
        }
    }
}
