#include "TeamLeader.h"

TeamLeader::TeamLeader(const string& name, const string& hiring_date, shift working_shift, float hourly_rate, size_t worked_hours,
	size_t learning_bonus, size_t required_hours, size_t visited_hours, size_t percentage_per_worker)
		:ProductionWorker(name, hiring_date, working_shift, hourly_rate, worked_hours)
{
	
	
	set_required_hours(required_hours);
	set_visited_hours(visited_hours);
	set_learning_bonus(learning_bonus);
	set_percentage_per_worker(percentage_per_worker);
	
	number_of_workers == 0 ? workers_arr = new ProductionWorker[number_of_workers + 1]{} : workers_arr = new ProductionWorker[number_of_workers]{};
}

TeamLeader::TeamLeader()
{
	learning_bonus = 500;
	required_hours = MIN_REQUIRED_HOURS;
	visited_hours = 0;
	percentage_per_worker = MIN_PERCENTAGE_PER_WORKER;
	number_of_workers = 0;
}

void TeamLeader::set_learning_bonus(size_t learning_bonus)
{
	visited_hours < required_hours ? this->learning_bonus = 0 : this->learning_bonus = learning_bonus;
}

void TeamLeader::set_required_hours(size_t required_hours)
{
	required_hours > 0 ? this->required_hours = required_hours : this->required_hours = MIN_REQUIRED_HOURS;
}

void TeamLeader::set_visited_hours(size_t visited_hours)
{
	visited_hours > 0 ? this->visited_hours = visited_hours : this->visited_hours = 0;
}

void TeamLeader::set_percentage_per_worker(size_t percentage_per_worker)
{
	percentage_per_worker > 0 && percentage_per_worker <= MAX_PERCENTAGE_PER_WORKER ? 
	this->percentage_per_worker = percentage_per_worker : this->percentage_per_worker = MIN_PERCENTAGE_PER_WORKER;
}

size_t TeamLeader::get_learning_bonus() const
{
	return learning_bonus;
}

size_t TeamLeader::get_workers_bonus() const
{
	return (get_monthly_salary() * (get_number_of_workers() * get_percentage_per_worker()))/100;
}

size_t TeamLeader::get_required_hours() const
{
	return required_hours;
}

size_t TeamLeader::get_visited_hours() const
{
	return visited_hours;
}

size_t TeamLeader::get_percentage_per_worker() const
{
	return percentage_per_worker;
}

size_t TeamLeader::get_number_of_workers() const
{
	return number_of_workers;
}

float TeamLeader::get_monthly_salary() const
{
	return get_hourly_rate() * get_worked_hours();
}

void TeamLeader::add_worker(ProductionWorker& the_worker)
{
	if (number_of_workers == 0)
	{
		number_of_workers++;
		workers_arr = new ProductionWorker[number_of_workers]{};
		workers_arr[number_of_workers - 1] = the_worker;

	}
	else if (number_of_workers > 0)
	{
		ProductionWorker* new_arr = new ProductionWorker[number_of_workers + 1];
		for (int i = 0; i < number_of_workers; i++)
		{
			new_arr[i] = workers_arr[i];
		}
		new_arr[number_of_workers] = the_worker;
		delete[] this->workers_arr;
		workers_arr = new_arr;
		number_of_workers++;
	}
}

void TeamLeader::print_employee_info() const
{
	cout << endl;
	ProductionWorker::print_employee_info();
	cout << "\nlearning bonus - " << learning_bonus << "\trequired hours of study - " << required_hours << "\tvisited hours of study - " << visited_hours << "\t percentage per one worker - " << percentage_per_worker << "\n";
}

void TeamLeader::print_workers_list() const
{
	cout << "\n\t\tList of workers:" << "\t\t\tteam leader: " <<this->get_name() << "\n--------------------------------------------------------------------------------------------------------" << endl;
	cout << "\tName\t|\t" << "Shift\t|\t" << "Hourly rate\t|\t" << "Worked hours\t|\t"<< "Hiring date \t|\t" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < number_of_workers; i++)
	{
		cout << "\t" << workers_arr[i].get_name() << "\t\t";
		workers_arr[i].show_shift(workers_arr[i].get_working_shift());
		cout << "\t  ";
		cout << workers_arr[i].get_hourly_rate() << "     \t\t";
		cout << workers_arr[i].get_worked_hours() << "\t\t\t";
		cout << workers_arr[i].get_hiring_date() << "\n";
		cout << "-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -" << endl;
	}
}

void TeamLeader::print_team_leader_info() const
{
	cout << "\nNumber of workers in " << get_name() << "'s team -  \t" << get_number_of_workers();
	cout << "\nRequired hours of study -  \t\t" << get_required_hours();
	cout << "\nVisited hours of study -  \t\t" << get_visited_hours();
	cout << "\nPercentage per one worker -  \t\t" << get_percentage_per_worker();
	cout << "\n\nMonthly salary -    \t\t\t" << get_monthly_salary();
	cout << "\nBonus for all workers -  \t\t" << get_workers_bonus();
	cout << "\nBonus for learning -  \t\t\t" << get_learning_bonus();
	cout << "\nTotal salary -  \t\t\t" << get_learning_bonus() + get_workers_bonus() + get_monthly_salary() << endl;
}

void TeamLeader::set_worker_bonus()
{
	this->workers_bonus = ((get_worked_hours() * get_hourly_rate()) * (number_of_workers * percentage_per_worker)) / 100;
}

TeamLeader::~TeamLeader()
{
	delete[] workers_arr;
}
