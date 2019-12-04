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
using System.Data.OleDb;
using System.Data;

namespace _2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        static string _mdbFile = @"D:\work\mycode\vscode_code\git_project\MyUniversity\csharp_language_programming\code\experiment\2.6\Northwind.mdb";
        static OleDbConnection _connection;
        string connString = @"Provider=Microsoft.ACE.OLEDB.12.0; Data Source=" + _mdbFile;
        static OleDbDataAdapter _adapter;
        static DataSet _dataset;
        public MainWindow()
        {
            InitializeComponent();
            _connection = new OleDbConnection(connString);
            _connection.Open();
            try
            {
                if (_connection.State == ConnectionState.Open)
                {
                    MessageBox.Show("数据已经成功连接");
                }
            }
            catch
            {
                MessageBox.Show("数据库连接失败");
            }
        }
        private void comboBox1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
        }
        private void button1_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                dataGrid.CanUserDeleteRows = true;
                _adapter = new OleDbDataAdapter();
                _dataset = new DataSet();
                var command = _connection.CreateCommand();
                string searchpattern = "select * from 订单 where " + comboBox1.Text + " like '%" + textBox1.Text + "%'";
                //MessageBox.Show(searchpattern);
                command.CommandText = searchpattern;
                command.CommandType = CommandType.Text;
                OleDbDataAdapter adapter = new OleDbDataAdapter(command);
                DataTable table = new DataTable("订单");
                adapter.Fill(table);
                dataGrid.ItemsSource = table.AsDataView();
                OleDbDataReader reader = command.ExecuteReader();
                reader.Read();
                List<string> columns = new List<string>();
                for (int i = 0; i < reader.FieldCount; i++)
                {
                    columns.Add(reader.GetName(i));
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            //dataGrid1.ItemsSource = columns;
        }
        private void dataGrid1_Loaded(object sender, RoutedEventArgs e)
        {
        }
    }
}
