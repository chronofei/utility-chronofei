#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <cassert>
#include <string>
#include <sstream>

void ModifyContend(std::vector<std::string> &contends) {
	int col_num = 0;
	int row_num = 0;
	
	for(auto& contend:contends) {
		// if(row_num == 0) {
		// 	row_num++;
		// 	continue;
		// }
		std::istringstream sin(contend);
		std::vector<std::string> fields;
		std::string field;
		int count_delimiter = 0;
		char delimiter = ',';
		contend.clear();
		while (std::getline(sin, field, delimiter)) {
			count_delimiter++;
			if(count_delimiter == 2) {
				std::cout<<"field "<<field<<std::endl;
				field = "纬度(°)";
			} else if (count_delimiter == 3) {
				field = "经度(°)";
			} else if (count_delimiter == 20) {
				// field = "目标加速度(m/s^2)";
			}
			contend+=(field+',');
		}
		contend.pop_back();
		col_num = std::max(col_num, count_delimiter);
		row_num++;
		break;
	}
	// row_num = 0;
	// for(auto& contend:contends) {
	// 	if(row_num == 0) {
	// 		row_num++;
	// 		continue;
	// 	}
	// 	std::istringstream sin(contend);
	// 	std::vector<std::string> fields;
	// 	std::string field;
	// 	int count_delimiter = 0;
	// 	bool found_traffic = false;
	// 	char delimiter = ',';
	// 	contend.clear();
	// 	while (std::getline(sin, field, delimiter)) {
	// 		count_delimiter++;
	// 		if(count_delimiter == 43) {
	// 			//std::cout<<"contend[43]: "<<field<<std::endl;
	// 			found_traffic = std::stoi(field) == 1;
	// 			fields.emplace_back(field);
	// 			contend+=(field+',');
	// 			continue;
	// 		} else if (found_traffic) {
	// 			if(col_num == 55) {
	// 				if(count_delimiter == 45) field = "left";
	// 				else if(count_delimiter == 49) field = "straight";
	// 				else if(count_delimiter == 53) field = "right";
	// 			} else if(col_num == 47) {
	// 				if(count_delimiter == 45) field = "straight";
	// 			}
	// 		}
	// 		contend+=(field+',');
	// 		fields.emplace_back(field);
			
	// 	}
	// 	contend.pop_back();
	// 	row_num++;
	// }
	std::cout<<"max col_num is "<<col_num<<" max row_num is "<<row_num<<std::endl;
}

int main(int argc, char **argv){
	//std::cout<<"argc = "<<argc<<std::endl;
	for(int i = 1; i < argc; i++) {
		std::cout<<"csv_list_file: "<<argv[i]<<std::endl;
		std::ifstream csv_list(argv[i]);
		std::string file;
		while(std::getline(csv_list, file)) {
			std::ifstream input_csv;
			std::cout<<"\nfile path: "+file<<std::endl;
			input_csv.open(file ,std::ios::app);
			assert(input_csv.is_open());
			// input
			std::string line;
			std::vector<std::string> contends;
			while(input_csv.good())
			{
				getline(input_csv, line);
				contends.push_back(line);
			}
			std::cout<<"csv input size: "<<contends.size()<<std::endl;
			input_csv.close();
			// modify
			ModifyContend(contends);
			// output
			std::ofstream output_csv(file);
			std::cout<<"now on writing process, row size: "<<contends.size()<<std::endl;
			for(int i = 0; i < contends.size(); i++) {
				output_csv<<contends.at(i)<<std::endl;
			}
			output_csv.close();
			usleep(100 * 1000);
		}
		usleep(100 * 1000);
	}
	return 0;
}

