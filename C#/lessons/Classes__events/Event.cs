using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lessons
{
    class Event
    {
        string event_name;
        string event_place;
        uint amount_persons;
        DateTime event_date;
        int event_id;
        static int counter; 
        Client client;
        public readonly uint MinAmountPersons = 1;
        public readonly int DaysInWeek = 7;
        // Ctors
        public Event(string event_name, string event_place, uint amount_persons, Client client, DateTime event_date = default)
        {
            ++counter;
            this.EventName = event_name;
            this.EventPlace = event_place;
            this.AmountPersons = amount_persons;
            this.client = client;
            this.EventDate = event_date;
            this.EventID = counter;
            
        }
        public Event() : this("NoName", "NoName", 1, new Client())
        {
        }
        // Properties
        public string EventName
        {
            get => event_name;
            set => event_name = !string.IsNullOrWhiteSpace(value) ? value : "NoName";
        }
        public string EventPlace
        {
            get => event_place;
            set => event_place = !string.IsNullOrWhiteSpace(value) ? value : "NoName";
        }
        public uint AmountPersons
        {
            get => amount_persons;
            set => amount_persons = value > 0 ? value : MinAmountPersons;
        }
        public Client EventClient
        {
            get => client;
        }
        public DateTime EventDate
        {
            get => event_date;
            set
            {
                if (value >= DateTime.Now)
                {
                    event_date = value;
                }
                else
                {
                    event_date = DateTime.Now;
                }
            }
        }
        public int EventID
        {
            get => event_id;
            set => event_id = counter;
        }
        // Methods
        public override string ToString() => $"===============================\nEvent ID : {EventID}\nEvent name : {event_name,-10}\nEvent place : {event_place,-10}\nAmount of persons : {amount_persons},\nEvent date : {event_date :d}\nClient : {client.Name}\nContact : {client.PhoneNumber}";
        public void MoveEventDay(int days)
        {
            EventDate = EventDate.AddDays(days);
        }
        public void MoveEventWeek(int weeks)
        {
            EventDate = EventDate.AddDays(weeks * DaysInWeek);
        }
    }
}
