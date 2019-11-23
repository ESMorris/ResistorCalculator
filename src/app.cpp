#include <server.h>


using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

    server.renderHTML("/", "index.html");


    server.route("/resistance", [&](const request& req, response& res){

        if (req.has_params({"b1", "b2", "b3", "b4", "b5"})){
            // create 3 unordered maps
            std::unordered_map<std::string, double> band;
            std::unordered_map<std::string, double> multiplier;
            std::unordered_map<std::string, std::string> tolerance;


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
