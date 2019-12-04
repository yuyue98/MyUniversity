using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.OleDb;
using System.Data;
using System.Data.Common;

namespace _1
{
    class Test
    {
        static string _mdbFile = @"D:\work\mycode\vscode_code\git_project\MyUniversity\csharp_language_programming\code\experiment\2.6\Northwind.mdb";
        static OleDbConnection _connection;
        static OleDbDataAdapter _adapter;
        static DataSet _dataset;

        public static void Main(string[] argv)
        {
            while (true)
            {
                int index = 1;
                Console.WriteLine("=====Menu=====");
                Console.WriteLine(index++ + ". 连接数据库");
                Console.WriteLine(index++ + ". 查询数据行");
                Console.WriteLine(index++ + ". 数据统计");
                Console.WriteLine(index++ + ". 更新数据库");
                Console.WriteLine(index++ + ". 数据库离线查询");
                Console.WriteLine(index++ + ". 离线LINQ查询");
                Console.WriteLine(index++ + ". 断开数据库");
                Console.WriteLine(index++ + ". 退出");
                Console.WriteLine("=====End======");
                Console.Write("请选择一个操作：");

                string input = Console.ReadLine();
                int choice;
                bool isDigit = int.TryParse(input, out choice);
                if (!isDigit || choice >= index || choice < 1)
                {
                    Console.WriteLine("错误选项");
                }

                if (choice == index - 1)
                    break;

                switch (choice)
                {
                    case 1:
                        ConnectToDB();
                        break;
                    case 2:
                        QueryWithReader();
                        break;
                    case 3:
                        QueryScalar();
                        break;
                    case 4:
                        UpdateOnLine();
                        break;
                    case 5:
                        QueryOffLine();
                        break;
                    case 6:
                        LINQQuery();
                        break;
                    case 7:
                        CloseDB();
                        break;
                }
                Console.WriteLine();
            }
        }

        public static bool IsConnected()
        {
            if (_connection == null || _connection.State != ConnectionState.Open)
            {
                Console.WriteLine("数据库未连接");
                return false;
            }
            return true;
        }

        public static void ConnectToDB()
        {
            try
            {
                string connString = @"Provider=Microsoft.ACE.OLEDB.12.0; Data Source=" + _mdbFile;
                _connection = new OleDbConnection(connString);
                //补全
                _connection.Open();
                if (_connection.State == ConnectionState.Open)
                {
                    Console.WriteLine("数据库Northwind已经连接并打开");
                }
            }
            catch 
            {
                Console.WriteLine("数据库连接失败！");
            }
        }

        public static void QueryWithReader()
        {
            try
            {
                if (!IsConnected())
                    return;

                var command = _connection.CreateCommand();
                //补全
                Console.WriteLine("请输入表格名：");
                string str1 = Console.ReadLine();
                Console.WriteLine("请输入字段名：");
                string str2 = Console.ReadLine();
                Console.WriteLine("请输入你要查询的信息：");
                string str3 = Console.ReadLine();
                command.CommandText = "select * from "+str1+" where "+str2+" = " + "'"+str3+"'";
                OleDbDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Console.WriteLine(reader[0] + "\t" + reader[1] + "\t" +reader[2]);
                    //Console.WriteLine(reader["客户ID"]);
                    //int 字段个数 = reader.FieldCount;
                    //for (int i = 0; i < 字段个数; i++)
                    //{
                    //     if (!reader.IsDBNull(i))
                    //        reader.GetString(i);
                    //}
                }
                reader.Close();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public static void QueryScalar()
        {
            try
            {
                if (!IsConnected())
                    return;

                var command = _connection.CreateCommand();
                //补全
                Console.WriteLine("请输入表格名：");
                string str1 = Console.ReadLine();
                Console.WriteLine("请输入字段名：");
                string str2 = Console.ReadLine();
                Console.WriteLine("请输入你要查询的信息：");
                string str3 = Console.ReadLine();
                command.CommandText = "select count(*) from " + str1 + " where " + str2 + " = " + "'" + str3 + "'";
                Console.WriteLine("所查询的信息有" + command.ExecuteScalar() + "条");

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public static void UpdateOnLine()
        {
            try
            {
                if (!IsConnected())
                    return;

                DbCommand cmd = _connection.CreateCommand();
                cmd.CommandText = string.Format("UPDATE 客户 SET 城市='天津'WHERE 客户ID ='ALFKI'");
                int num = cmd.ExecuteNonQuery();
                Console.WriteLine("一共修改了" + num + "行");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }

        public static void QueryOffLine()
        {
            try
            {
                if (!IsConnected())
                    return;
                Console.WriteLine("请输入表格名：");
                string str1 = Console.ReadLine();
                _adapter = new OleDbDataAdapter("select * from " + str1 + " ", _connection);
                //_dataset = new DataSet();
                DataTable tb = new DataTable(str1);
                _adapter.Fill(tb);
                //DataTable dt = _dataset.Tables["客户"];
                //方法一， 直接引用
                //object obj = tb.Rows[0]["客户ID"];
                //方法二， 循环查询
                for (int i = 0; i < tb.Rows.Count; i++)
                {
                    for (int j = 0; j < tb.Columns.Count; j++)
                    {
                        Console.Write(tb.Rows[i][j] + " ");
                    }
                    Console.WriteLine();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            
        }

        public static void LINQQuery()
        {
            try
            {
                if (!IsConnected())
                    return;
                _adapter = new OleDbDataAdapter();
                _dataset = new DataSet();
                var command = _connection.CreateCommand();
                command.CommandText = "select * from 客户 where 城市='重庆'";
                _adapter.SelectCommand = command;
                _adapter.Fill(_dataset, "客户");
                DataTable table = _dataset.Tables[0];
                IEnumerable<DataRow> rows = from p in table.AsEnumerable() select p;
                Console.WriteLine("客户ID");
                foreach (DataRow row in rows)
                {
                    Console.WriteLine(row.Field<string>("客户ID"));
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public static void CloseDB()
        {
            try
            {
                if (!IsConnected())
                    return;
                _connection.Close();
                if (_connection.State == ConnectionState.Closed)
                {
                    Console.WriteLine("数据库Northwind已经成功关闭!");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
