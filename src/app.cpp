#include <server.h>


using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

    server.renderHTML("/", "index.html");
    
    // create 3 unordered maps
    std::unordered_map<std::string, double> band;
    std::unordered_map<std::string, double> multiplier;
    std::unordered_map<std::string, std::string> tolerance;

    // Set the values for each of the unordered maps
    // Set band values here
    band["Black"] = 0, band["Brown"] = 1, band["Red"] = 2;
    band["Orange"] = 3, band["Yellow"] = 4, band["Green"] = 5;
    band["Blue"] = 6, band["Violet"] = 7, band["Grey"] = 8, band["White"] = 9;
    // Set multiplier values here
    multiplier["Black"] = 1, multiplier["Brown"] = 10, multiplier["Red"] = 100;
    multiplier["Orange"] = 1000, multiplier["Yellow"] = 10000, multiplier["Green"] = 100000;
    multiplier["Blue"] = 1000000, multiplier["Violet"] = 10000000, multiplier["Gold"] = .1, multiplier["Silver"] = .01;
    // Set tolerance values here
    tolerance["Brown"] = " +/- 1% ", tolerance["Red"] = " +/- 2% ", tolerance["Green"] = " +/- .5% ";
    tolerance["Blue"] = " +/- .25% ", tolerance["Violet"] = " +/- .1% ", tolerance["Grey"] = " +/- .05% ";
    tolerance["Gold"] = " +/- 5% ", tolerance["Silver"] = " +/- 10% ";

    server.route("/resistance", [&](const request& req, response& res){

        if (req.has_params({"b1", "b2", "b3", "b4", "b5"})){
            // Get the inputs for each of the buttons
            std::string button_One = req.url_params.get("b1");
            std::string button_Two = req.url_params.get("b2");
            std::string button_Three = req.url_params.get("b3");
            std::string button_Four = req.url_params.get("b4");
            std::string button_Five = req.url_params.get("b5");

            std::cout << button_One << std::endl;
            std::cout << button_Two << std::endl;
            std::cout << button_Three << std::endl;
            std::cout << button_Four << std::endl;
            std::cout << button_Five << std::endl;


            ucm::json result;
            result["resistance"] = 1;
            result["tolerance"] = 1;
            res.sendJSON(result);
        }

        else{
            res.sendError400();
        }
    });

    server.run();
}



// band["black"] = 1
// band["brown"] = 2
// etc...
// multiplier["black"] = 1
//multiplier["brown"] = 10
// etc...
//tolerance["black"] = "+/- 1%"
// std::strings : b1, b2, b3, b4, b5
// band.at(b1) => 1
