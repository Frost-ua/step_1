#include "Menu.h"

void Menu::show_menu() const
{
	cout << "\t\t\t---===   Welcome to the zoo   ===---\n";
	int choice = 0;
	bool leave_zoo = false;
	Zoo zoo;

	while (!leave_zoo)
	{
		header();
		cin >> choice;

		switch (choice)
		{
		case 1: {
			string kind, name;
			system("Cls");
			cout << "\n\nThere are bears, parrots and crocodiles.\nEnter a kind of the animal: ";
			cin >> kind;
			cout << "Enter a name of the animal: ";
			cin >> name;
			zoo.add_animal(kind, name);
			system("Pause");
			system("Cls");
			break;
		}
		case 2: {
			string name;
			system("Cls");
			cout << "\n\nEnter a name of the worker: ";
			cin >> name;
			zoo.add_worker(name);
			cout << "The worker " << name << " was added successfully.\n\n";
			system("Pause");
			system("Cls");
			break;
		}
		case 3: {
			
			system("Cls");
			zoo.add_camera();
			cout << "\n\nCamera was added successfully.\n\n";
			system("Pause");
			system("Cls");
			break;
		}
		case 4: {
			system("Cls");
			cout << endl << endl;
			try
			{
				cout << "All the inhabitants of the zoo:\n\n";
				zoo.show_all_animals();
				cout << endl << endl;
			}
			catch (const string& ex)
			{
				cout << ex;
			}
			system("Pause");
			system("Cls");
			break;
		}
		case 5: {
			system("Cls");
			cout << endl << endl;
			try
			{
				cout << "All workers of the zoo:\n\n";
				zoo.show_all_workers();
				cout << endl << endl;
			}
			catch (const string& ex)
			{
				cout << ex;
			}
			system("Pause");
			system("Cls");
			break;
		}
		case 6: {
			system("Cls");
			cout << endl << endl;
			try
			{
				cout << "All cctv cameras of the zoo:\n\n";
				zoo.show_all_cctv_cameras();
				cout << endl << endl;
			}
			catch (const string& ex)
			{
				cout << ex;
			}
			system("Pause");
			system("Cls");
			break;
		}
		case 7: {
			system("Cls");
			string wrk_name, anml_name;
			cout << "\nChoose the worker who will feed the animal, enter the name: \n\n";
			try
			{
				cout << "The list of workers\n\n";
				zoo.show_all_workers();
			}
			catch (const string& ex)
			{
				cout << ex;
				system("Pause");
				break;
			}
			cin >> wrk_name;
			system("Cls");
			cout << "\nChoose the animal you want to feed, enter the name: \n\n";
			try
			{
				cout << "The list of animals\n\n";
				zoo.show_all_animals();
			}
			catch (const string& ex)
			{
				cout << ex;
				system("Pause");
				break;
			}
			cin >> anml_name;
			for (size_t i = 0; i < zoo.get_amount_animals(); i++)
			{
				if (zoo.get_list_of_animals()[i].get_name() == anml_name)
				{
					for (size_t j = 0; j < zoo.get_amount_workers(); j++)
					{
						if (zoo.get_list_of_workers()[j].get_zoo_worker_name() == wrk_name)
						{
							zoo.get_list_of_workers()[j].FeedAnimal(zoo.get_list_of_animals()[i]);
						}
					}
				}
			}
			system("Pause");
			system("Cls");
			break;
		}
		
		case 8: {
			try
			{
				system("Cls");
				cout << "\nAll the inhabitants of the zoo:\n\n";
				zoo.show_all_animals();
				cout << endl;
			}
			catch (const string& ex)
			{
				cout << ex;
				system("Pause");
				break;
			}
			cout << "Enter the name of the animal:\n";
			string name;
			cin >> name;
			bool flag = false;
			for (size_t i = 0; i < zoo.get_amount_animals(); i++)
			{
				if (zoo.get_list_of_animals()[i].get_name() == name)
				{
					flag = true;
				}
			}
			if (flag)
			{
				cout << "\nChoose the way of observe: \n\n1. Cctv camera.\n2. Zoo worker.\n\n";
				size_t choice = 0;
				cin >> choice;

				switch (choice)
				{
				case 1: {
					cout << "\nChoose camera, enter camera id:\n\n";
					try
					{
						cout << "The list of cctv cameras\n\n";
						zoo.show_all_cctv_cameras();
					}
					catch (const string& ex)
					{
						cout << ex;
						system("Pause");
						system("Cls");
						break;
					}
					size_t id = 0;
					cin >> id;
					for (size_t i = 0; i < zoo.get_amount_animals(); i++)
					{
						if (zoo.get_list_of_animals()[i].get_name() == name)
						{
							for (size_t j = 0; j < zoo.get_amount_cctv_cameras(); j++)
							{
								if (!zoo.get_list_of_cctv_cameras()[j].get_already_watching() && zoo.get_list_of_cctv_cameras()[j].get_id() == id)
								{
									zoo.get_list_of_cctv_cameras()[j].Watch(zoo.get_list_of_animals()[i]);
									system("Pause");
									system("Cls");
									break;
								}
								else if (zoo.get_list_of_cctv_cameras()[j].get_already_watching() && zoo.get_list_of_cctv_cameras()[j].get_object_of_observation() == name && zoo.get_list_of_cctv_cameras()[j].get_id() == id)
								{
									zoo.get_list_of_cctv_cameras()[j].set_already_watching(false);
									zoo.get_list_of_cctv_cameras()[j].Watch(zoo.get_list_of_animals()[i]);
									system("Pause");
									system("Cls");
									break;
								}
								else if (zoo.get_list_of_cctv_cameras()[j].get_already_watching() && zoo.get_list_of_cctv_cameras()[j].get_object_of_observation() != name && zoo.get_list_of_cctv_cameras()[j].get_id() == id)
								{
									cout << "Camera " << id << " is busy!\n\n";
									system("Pause");
									system("Cls");
									break;
								}
							}
						}
					}
					break;
				}
				case 2: {
					cout << "Choose zoo worker, enter the name:\n\n";
					try
					{
						cout << "The list of workers\n\n";
						zoo.show_all_workers();
					}
					catch (const string& ex)
					{
						cout << ex;
						system("Pause");
						system("Cls");
						break;
					}
					string worker_name;
					cin >> worker_name;
					for (size_t i = 0; i < zoo.get_amount_animals(); i++)
					{
						if (zoo.get_list_of_animals()[i].get_name() == name)
						{
							for (size_t j = 0; j < zoo.get_amount_workers(); j++)
							{
								if (!zoo.get_list_of_workers()[j].get_already_watching() && zoo.get_list_of_workers()[j].get_zoo_worker_name() == worker_name)
								{
									zoo.get_list_of_workers()[j].Watch(zoo.get_list_of_animals()[i]);
									system("Pause");
									system("Cls");
									break;
								}
								else if (zoo.get_list_of_workers()[j].get_already_watching() && zoo.get_list_of_workers()[j].get_object_of_observation() == name && zoo.get_list_of_workers()[j].get_zoo_worker_name() == worker_name)
								{
									zoo.get_list_of_workers()[j].set_already_watching(false);
									zoo.get_list_of_workers()[j].Watch(zoo.get_list_of_animals()[i]);
									system("Pause");
									system("Cls");
									break;
								}
								else if (zoo.get_list_of_workers()[j].get_already_watching() && zoo.get_list_of_workers()[j].get_object_of_observation() != name && zoo.get_list_of_workers()[j].get_zoo_worker_name() == worker_name)
								{
									cout << "Zoo worker " << worker_name << " is busy!\n\n";
									system("Pause");
									system("Cls");
									break;
								}
							}
						}
					}
					break;
				}
				default:
					cout << "Wrong value!\n";
					system("Pause");
					system("Cls");
					break;
				}
			}
			else
			{
				cout << "The animal with name " << name << " doesn't exist in our zoo!\n";
				break;
			}
			break;
		}
		case 0: {
			leave_zoo = true;
			break;
		}
		default:
			cout << "Wrong value!\n";
			system("Pause");
			system("Cls");
			break;
		}
	}
}

void Menu::header() const
{
	cout << "\n\n1. Add the animal.\n2. Add the worker.\n3. Add the camera.\n4. Show all animals.\n5. Show all workers.\n6. Show all cctv cameras.\n7. Feed an animal.\n8. Spy on the animal.\n0. Leave the zoo.\n\n";
}
