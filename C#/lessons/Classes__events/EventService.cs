using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lessons
{
    class EventService
    {
        List<Event> event_list = new List<Event>();

        public void AddEvent(Event new_event)
        {
            event_list.Add(new_event);
        }

        public void ClearAllEvents()
        {
            event_list.Clear();
        }
        public void DeleteEvent(int event_id)
        {
            int index_id = event_list.FindIndex(x => (x.EventID == event_id));         // ???????????????!!!!!!!!!!!!! where check finding???
            event_list.Remove(event_list[index_id]);
        }
        public void SearchEventByDate(DateTime date)
        {
            List<Event> result = event_list.FindAll(x => (x.EventDate == date));
            foreach (var e in result)
            {
                Console.WriteLine(e);
            }
            if (result.Capacity == 0)
            {
                Console.WriteLine("No events have been defined to date!");
            }
        }
        public void SearchEventByRangeDate(DateTime left_date, DateTime right_date)
        {
            List<Event> result = event_list.FindAll(x => (x.EventDate >= left_date && x.EventDate <= right_date));
            foreach (var e in result)
            {
                Console.WriteLine(e);
            }
            if (result.Capacity == 0)
            {
                Console.WriteLine("No events were found in this range of date!");
            }
        }
        public void SearchEventByClient(Client client)
        {
            List<Event> result = event_list.FindAll(x => (x.EventClient.Name == client.Name && x.EventClient.PhoneNumber == client.PhoneNumber));
            foreach (var e in result)
            {
                Console.WriteLine(e);
            }
            if (result.Capacity == 0)
            {
                Console.WriteLine("Client not found!");
            }
        }

        public override string ToString()
        {
            string result = string.Empty;
            foreach (var e in event_list)
            {
                result += e.ToString() + "\n";
            }
            return result;
        } 
    }
}
