#include <iostream>
#include <string>
#include <stdexcept> // Nécessaire pour std::invalid_argument et std::out_of_range

void test_conversion(const std::string& str)
{
    std::cout << "Conversion de \"" << str << "\" : ";
    try
    {
        // On tente la conversion
        int result = std::stoi(str);
        std::cout << "Succès -> " << result << std::endl;
    }
    // 1ère exception : la chaîne ne contient pas de nombre (ex: "bonjour")
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Erreur (invalid_argument) : la chaîne n'est pas un nombre." << std::endl;
    }
    // 2ème exception : le nombre est trop grand/petit pour rentrer dans un "int"
    catch (const std::out_of_range& e)
    {
        std::cerr << "Erreur (out_of_range) : le nombre dépasse la capacité d'un int." << std::endl;
    }
}

int main()
{
    /*
    test_conversion("-4.2f");              // Cas normal
    test_conversion("Mots seulement");  // Va déclencher std::invalid_argument
    test_conversion("99999999999999");  // Va déclencher std::out_of_range
    */
{
    char c = 200;
   std::cout << c << std::endl;
}
{
    char c = 40002;
   std::cout << c << std::endl;
}
{
    char c = 127;
   std::cout << c << std::endl;
}

    return 0;
}
