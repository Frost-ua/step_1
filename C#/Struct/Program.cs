using System;
using System.Collections.Generic;

namespace Struct
{
    enum TypeArticle { None, Shoes, Clothes, Inventary};

    struct Article
    {

        public string Article_Brand { get; set; }
        public uint Article_Price { get; set; }
        public readonly int Article_Id;
        static int last_article_id;
        public TypeArticle article_type;

        public Article(TypeArticle article_type = TypeArticle.None, string article_brand = "NoBrand", uint article_price = 0)
        {
            this.Article_Brand = article_brand;
            this.Article_Price = article_price;
            this.article_type = article_type;
            Article_Id = ++last_article_id;
        }

        public override string ToString() => $"ID:{Article_Id}\t\tType of article : {article_type} \t\tBrand : {Article_Brand}\t\tPrice : {Article_Price}";

        /* public TypeArticle ArticleType
             {
                 get => article_type;
                 set => article_type = (Enum.IsDefined(typeof(TypeArticle), value)) ? value : TypeArticle.None;
             }*/

    }

    struct RequestItem
    {
        Article article;
        uint number_of_articles;
        public readonly uint Min_number_of_articles;

        public RequestItem(Article article, uint number_of_articles)
        {
            Min_number_of_articles = 1;
            this.article = article;
            this.number_of_articles = Min_number_of_articles;
            Number_of_articles = number_of_articles;
        }
    
        public Article GetArticle
        {
            get => article;
        }
        public uint Number_of_articles
        {
            get => number_of_articles;
            set => number_of_articles = number_of_articles >= 0 ? value : Min_number_of_articles;  

        }
        public override string ToString() => $"Article:{article}\tquantity  {number_of_articles}\n";
    }

    struct Request
    {
        public readonly int Request_Id;
        static int last_request_id;
        Client client;
        DateTime request_date;
        List<RequestItem> order_list;
        public readonly uint order_amount;

       public Request(Client client, DateTime date)
        {
            order_list = new();
            this.client = client;
            request_date = date;
            Request_Id = ++last_request_id;
            order_amount = 0; 
        }
       
       public void AddRequestItem(RequestItem ri)
        {
            Order_list.Add(ri);
            client.Total_amount_of_orders = 0;
            client.Number_of_client_orders = 0;
            for (int i = 0; i < Order_list.Count; i++)
            {
                client.Total_amount_of_orders += (order_list[i].GetArticle.Article_Price * order_list[i].Number_of_articles);
                ++client.Number_of_client_orders;
            }
        }

        public void RemoveRequestItem(uint article_id)
        {
            bool is_deleted = false;
            for (int j = 0; j < Order_list.Count; j++)
            {
                if (Order_list[j].GetArticle.Article_Id == article_id)
                {
                    Order_list.Remove(Order_list[j]);
                    is_deleted = true;
                }
            }
            if (is_deleted)
            {
                client.Total_amount_of_orders = 0;
                client.Number_of_client_orders = 0;
                for (int i = 0; i < Order_list.Count; i++)
                {
                    client.Total_amount_of_orders += (order_list[i].GetArticle.Article_Price * order_list[i].Number_of_articles);
                    ++client.Number_of_client_orders;
                }
            }
            else 
            {
                Console.WriteLine("\nIncorrect article ID.\n");
            }
            
        }
        public uint Order_amount
        {
            get {
                uint sum = 0;
                
                for (int i = 0; i < order_list.Count; i++)
                {
                    sum += (order_list[i].GetArticle.Article_Price * order_list[i].Number_of_articles);
                }
                return sum;
            }
        }
        public List<RequestItem> Order_list
        {
            get => order_list;  
        }
        public override string ToString()
        {
            return $"Request ID: {Request_Id}\n{client}\nRequest date : {request_date :d}\nOrder list :\n{string.Join("", order_list)}";

        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Client jordy = new Client("Jordy Frost", "Rivne", "0967217411");
            Client alex = new Client("Alex Frost", "Kyiv", "0687832129");

            Request r1 = new Request(jordy, new DateTime(2021, 10, 04));
            Request r2 = new Request(alex, new DateTime(2021, 11, 04));
            
            r1.AddRequestItem(new RequestItem(new Article(TypeArticle.Shoes, "Nike", 2600), 1));
            r1.AddRequestItem(new RequestItem(new Article(TypeArticle.Inventary, "Adidas", 650), 5));
            r1.AddRequestItem(new RequestItem(new Article(TypeArticle.Clothes, "Puma", 3200), 1));

            Console.WriteLine("===================   Full information about request from Jordy Frost after adding 3 articles   =================");
            Console.WriteLine(r1);
            Console.WriteLine("===================   After deleting article (ID 2) by Jordy Frost   =================================");
            r1.RemoveRequestItem(article_id: 2);
            Console.WriteLine(r1);
            Console.WriteLine("===================   Full information about request from Alex Frost before adding some articles   =================");
            Console.WriteLine(r2);
            Console.WriteLine("===================   Full information about request from Alex Frost before adding 4 articles   ===================");
            r2.AddRequestItem(new RequestItem(new Article(TypeArticle.Inventary, "Volkl", 10200), 1));
            r2.AddRequestItem(new RequestItem(new Article(TypeArticle.Shoes, "Columbia", 3300), 1));
            r2.AddRequestItem(new RequestItem(new Article(TypeArticle.Clothes, "Merrell", 1200), 1));
            r2.AddRequestItem(new RequestItem(new Article(TypeArticle.Clothes, "Salomone", 900), 1));
            Console.WriteLine(r2);
        }
    }
}
