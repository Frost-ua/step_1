#pragma once
#include <iostream>
#include <string>
#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker
{

public:
	TeamLeader(const string& name, const string& hiring_date, shift working_shift, float hourly_rate, size_t worked_hours,
		size_t learning_bonus, size_t required_hours, size_t visited_hours, size_t percentage_per_worker);
	TeamLeader();

	void set_learning_bonus(size_t learning_bonus);
	void set_required_hours(size_t required_hours);
	void set_visited_hours(size_t visited_hours);
	void set_percentage_per_worker(size_t percentage_per_worker);
	

	size_t get_learning_bonus() const;
	size_t get_workers_bonus() const;
	size_t get_required_hours() const;
	size_t get_visited_hours() const;
	size_t get_percentage_per_worker() const;
	size_t get_number_of_workers() const;
	float get_monthly_salary() const;

	void add_worker(ProductionWorker& the_worker);
	void print_employee_info() const;
	void print_workers_list() const;
	void print_team_leader_info() const;

	~TeamLeader();

private:
	static const size_t MIN_REQUIRED_HOURS = 10;
	static const size_t MAX_PERCENTAGE_PER_WORKER = 15;
	static const size_t MIN_PERCENTAGE_PER_WORKER = 3;
	size_t learning_bonus;
	size_t workers_bonus;
	size_t required_hours;
	size_t visited_hours;
	size_t percentage_per_worker;
	size_t number_of_workers = 0;
	ProductionWorker* workers_arr = nullptr;

	void set_worker_bonus();



};

