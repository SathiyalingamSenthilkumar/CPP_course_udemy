// Section 19 - Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void ruler();

int main(){
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    std::cout<<std::endl;
    for(int i=0; i<7; i++){
      ruler();//Each rule is 10==> 70
    }
    std::cout<<std::endl<<std::endl;
    
    // Unformatted display so you can see how to access the vector elements
    // Center title
    size_t start = ((70/2)-tours.title.length()/2);
    std::cout <<std::setw(start+tours.title.length())<<tours.title << std::endl<<std::endl;

    std::cout<<std::setw(20)<<std::left<<"Country"
	     <<std::setw(25)<<std::left<<"City"
	     <<std::setw(20)<<std::left<<"Population"
	     <<""<<"Price"<<std::endl; //Ending perfectly at 70

    std::cout<<std::setfill('-');
    std::cout<<std::setw(70)<<'-'<<std::endl;
    std::cout<<std::setfill(' '); //Change it back as it is persistent

    std::cout<<std::setprecision(2)<<std::fixed; //Fixes the precision after decimal point
   
    int loopCount = 0;
    
    for(auto country : tours.countries) {   // loop through the countries
      std::cout<<std::left<< country.name;
        for(auto city : country.cities) {       // loop through the cities for each country
	  if(loopCount == 0){
	    std::cout << std::setw(20-country.name.length()+city.name.length())<<std::right<< city.name;
	  }
	  else{
	    std::cout << std::setw(20+city.name.length())<<std::right<< city.name; 
	    }
	  std::cout<< std::setw(35-city.name.length())<<std::right << city.population 
		   << std::setw(15)<<std::right<< city.cost 
		   << std::endl;
	  loopCount++;
        }
	loopCount = 0;
    }

    std::cout << std::endl << std::endl;
    return 0;
}


void ruler(){
  std::cout<<"1234567890";
}
