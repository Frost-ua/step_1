using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel
{
    [Serializable]
    public class Order
    {
        public string Name { get; set; }
        public string LastName { get; set; }
        public string Phone { get; set; }
        public string Email { get; set; }
        public int Amount { get; set; }
        public string RoomType { get; set; }
        public DateTime StartDate { get; set; }
        public DateTime EndDate { get; set; }
        public string Message { get; set; }

        public Order(string name, string last_name, string phone, string email, int amount, string room_type, DateTime start_date, DateTime end_date , string message)
        {
            Name = name;
            LastName = last_name;
            Phone = phone;
            Email = email;
            Amount = amount;
            RoomType = room_type;
            StartDate = start_date;
            EndDate = end_date;
            Message = message;
        }
        public override string ToString()
        {
            return $"Name: {Name}\nLast name: {LastName}\nPhone: {Phone}\nEmail: {Email}\nAmount of people: {Amount}\nRoom type: {RoomType}\nPeriod: {StartDate.ToString("dd/MM/yyyy")} ... {EndDate.ToString("dd/MM/yyyy")}\nMessage: {Message}";
        }
    }

}
