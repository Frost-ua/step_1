using Microsoft.IdentityModel.Protocols;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HW_SQL_Library
{
    class Program
    {
        static void Main(string[] args)
        {
            // create connection string, use App.config xml
            string connectionString = ConfigurationManager.ConnectionStrings["connStr"].ConnectionString;

            //create connection
            SqlConnection connection = new SqlConnection(connectionString);

            // connect to server
            connection.Open();
            // menu
            Console.WriteLine("\t\t\tMenu:\n\n1. Add a new book to the library." +
                "\n2. Show the number of registered users" +
                "\n3. Show all debtors." +
                "\n4. Show a list of authors of particular book." +
                "\n5. Show a list of books that are currently available." +
                "\n6. Show a list of books that are in a specific user." +
                "\n7. Clear the debts of all debtors. \n\nMake your choice:");

            int choice;
            choice = int.Parse(Console.ReadLine());
            switch (choice)
            {
                case 1:
                    AddBook(GetBookInfoFromUser(), connection);
                    break;
                case 2:
                    Console.WriteLine($"Numder of registered visitors : {CountOfVisitors(connection)}.");
                    break;
                case 3:
                    ShowAllDebtors(connection);
                    break;
                case 4:                                     
                    Console.Write("Enter name of book:\t");                     //e.g.  Moby Dick
                    string bookName = Console.ReadLine();
                    ShowAurhorsOfBook(connection, bookName);
                    break;
                case 5:
                    ShowAvailableBooks(connection);
                    break;
                case 6:
                    Console.Write("Enter name of visitor:\t");                   //e.g.  Enrika Ferris
                    string visitorName = Console.ReadLine();
                    ShowBooksInVisitor(connection, visitorName);
                    break;
                case 7:
                    ClearAllDebtors(connection);
                    break;
                default:
                    Console.WriteLine("Incorrect value!");
                    break;
            }
            // disconnect server
            connection.Close();
        }

        static void AddBook(Book book, SqlConnection conn)
        {
            // create query   (query + connections)
            string cmdText = @"INSERT Books VALUES (@name, @pages, @publishDate, @price)";
            SqlCommand command = new SqlCommand(cmdText, conn);
            command.CommandTimeout = 5;

            // a safe option to get users query
            command.Parameters.Add("@name", System.Data.SqlDbType.NVarChar).Value = book.Name;
            command.Parameters.Add("@pages", System.Data.SqlDbType.Int).Value = book.Pages;
            command.Parameters.Add("@publishDate", System.Data.SqlDbType.DateTime).Value = book.PublishDate;
            command.Parameters.Add("@price", System.Data.SqlDbType.Money).Value = book.Price;

            // executes the command insert, update, delete and returns the number of rows that were involved
            int rows = command.ExecuteNonQuery();
            Console.WriteLine(rows + " rows affected");
        }
        static int CountOfVisitors(SqlConnection conn)
        {
            // create query   (query + connections)
            string cmdText = @"SELECT COUNT(v.Id) FROM Visitors AS v";
            SqlCommand command = new SqlCommand(cmdText, conn);
            command.CommandTimeout = 5;

            // Execute Scalar - executes a command that returns a single value
            return (int)command.ExecuteScalar();
        }
        static void ShowAllDebtors(SqlConnection conn)
        {
            // create query   (query + connections)
            string cmdText = @"SELECT * FROM Visitors WHERE IsDebtor = 1";
            SqlCommand command = new SqlCommand(cmdText, conn);
            command.CommandTimeout = 5;

            //ExecuteReader - executes the select command and returns the result as DbDataReader
            SqlDataReader reader = command.ExecuteReader();

            //Console.OutputEncoding = Encoding.UTF8;

            // print reader table
            CreateTable(reader, -23);
            reader.Close();
        }
        static void ShowAurhorsOfBook(SqlConnection conn, string bookName)
        {
            // create query   (query + connections)
            string cmdText = @"SELECT DISTINCT a.FirstName + ' ' + a.LastName AS 'Name of author' 
                               FROM Authors AS a JOIN BooksAuthors AS ba ON ba.AuthorId = a.Id 
                               JOIN Books AS b ON ba.BookId = b.Id 
                               WHERE b.[Name] LIKE  @bookName";
            SqlCommand command = new SqlCommand(cmdText, conn);
            command.CommandTimeout = 5;

            // a safe option to get users query
            command.Parameters.Add("@bookName", System.Data.SqlDbType.NVarChar).Value = "%" + bookName + "%";

            //ExecuteReader - executes the select command and returns the result as DbDataReader
            SqlDataReader reader = command.ExecuteReader();
            // print reader table
            CreateTable(reader);
            reader.Close();
        }
        static void ShowAvailableBooks(SqlConnection conn)
        {
            // create query   (query + connections)
            string cmdText = @"SELECT b.[Name] AS 'Name of book', b.Pages
                             FROM Books AS b JOIN BooksVisitors AS bv ON bv.BookId = b.Id JOIN Visitors AS v ON bv.VisitorId = v.Id
                             WHERE v.IsDebtor = 0";
            SqlCommand command = new SqlCommand(cmdText, conn);
            command.CommandTimeout = 5;

            //ExecuteReader - executes the select command and returns the result as DbDataReader
            SqlDataReader reader = command.ExecuteReader();
            // print reader table
            CreateTable(reader, -50);
            reader.Close();
        }
        static void ShowBooksInVisitor(SqlConnection conn, string visitorName)
        {
            // create query   (query + connections)
            string cmdText = @"SELECT b.[Name] AS 'Name of book', b.Pages FROM Books AS b JOIN BooksVisitors AS bv ON bv.BookId = b.Id
                               JOIN Visitors AS v ON bv.VisitorId = v.Id
                               WHERE v.FirstName + ' ' + v.LastName LIKE @visitorName";
            SqlCommand command = new SqlCommand(cmdText, conn);
            command.CommandTimeout = 5;

            // a safe option to get users query
            command.Parameters.Add("@visitorName", System.Data.SqlDbType.NVarChar).Value = "%" + visitorName + "%";

            //ExecuteReader - executes the select command and returns the result as DbDataReader
            SqlDataReader reader = command.ExecuteReader();
            // print reader table
            CreateTable(reader, -30);
            reader.Close();

        }
        static void ClearAllDebtors(SqlConnection conn)
        {
            // create query   (query + connections)
            string cmdText = @"UPDATE Visitors SET IsDebtor = 0 WHERE IsDebtor = 1";     
            SqlCommand command = new SqlCommand(cmdText, conn);
            command.CommandTimeout = 5;
            // executes the command insert, update, delete and returns the number of rows that were involved
            int rows = command.ExecuteNonQuery();                                                                                                               
            Console.WriteLine(rows + " rows affected");
        }
        static Book GetBookInfoFromUser()
        {
            Console.Write("Enter name of book:\t");
            string bookName = Console.ReadLine();
            Console.Write("Enter number of pages:\t");
            uint pages = uint.Parse(Console.ReadLine());
            Console.Write("Enter publish date(yyyy/mm/dd):\t");
            DateTime date = DateTime.Parse(Console.ReadLine());
            Console.Write("Enter price:\t");
            uint price = uint.Parse(Console.ReadLine());
            return new Book { Name = bookName, Pages = pages, PublishDate = date, Price = price };
        }
        static void CreateTable(SqlDataReader reader, int shift = -23)
        {
            string s = "{0," + shift +"}";
            Console.WriteLine();
            // print name of each column
            for (int i = 0; i < reader.FieldCount; i++)         
            {
                Console.Write(s, reader.GetName(i));
            }
            Console.WriteLine("\n-------------------------------------------------------------------------------------------------------------------");
            
            // print value of each row while reader return something
            while (reader.Read())                               
            {
                for (int i = 0; i < reader.FieldCount; i++)
                {
                    Console.Write(s, reader[i]);
                }
                Console.WriteLine();
            }
            Console.WriteLine("-------------------------------------------------------------------------------------------------------------------\n\n");

        }

        class Book
        {
            public string Name { get; set; }
            public uint Pages { get; set; }
            public DateTime PublishDate { get; set; }
            public decimal Price { get; set; }
        }
    }



}


