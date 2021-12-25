// #include <iostream>
// #include <sstream>
// #include <iomanip>
// #include <ctime>
//
// void try_time_put(const std::tm* t, const std::string& fmt)
// {
//         std::cout.imbue(std::locale());
//         std::cout << "In the locale '" << std::cout.getloc().name() << "' : '";
//
//         std::use_facet<std::time_put<char>>(std::cout.getloc()).put(
//                     {std::cout}, std::cout, ' ', t, &fmt[0], &fmt[0] + fmt.size());
//
//         std::cout << "'\n";
// }
//
// int main()
// {
//     std::time_t t = std::time(NULL);
//     std::tm tm = *std::localtime(&t);
//
//     std::string fmt = "%c";
//     std::cout << "Using the format string '" << fmt
//               << "' to format the time: " << std::ctime(&t) << '\n';
//
//     std::locale::global(std::locale("en_US.utf8"));
//     try_time_put(&tm, fmt);
//
//     std::locale::global(std::locale("ja_JP.utf8"));
//     try_time_put(&tm, fmt);
// }

#include <locale>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>

std::string get_date_string(const std::time_t &input_time, const std::locale &loc){
     std::tm * time = std::localtime ( &input_time );

     const std::time_put<char>& tmput = std::use_facet <std::time_put<char> > (loc);

     std::stringstream s;
     s.imbue(loc);

     std::tm *my_time=std::localtime( &input_time );
     tmput.put (s, s, ' ', my_time, 'x');

     return s.str();
}

int main(){

      std::time_t timestamp;
      std::time( &timestamp );

      std::cout<<"user settings: "<<get_date_string(timestamp, std::locale(""))<<"\n";
      std::cout<<"global settings: "<<get_date_string(timestamp, std::locale("en_US.utf8"))<<"\n";
      std::cout<<"C settings: "<<get_date_string(timestamp, std::locale::classic())<<"\n";
}
