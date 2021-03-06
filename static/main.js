$(document).ready(function(){
    $("#Calculate").click(function(){
        // variables to pass to the endpoint
        var b1= $("#1band").val();
        var b2 = $("#2band").val();
        var b3= $("#3band").val();
        var b4 = $("#multiplier").val();
        var b5= $("#tolerance").val();
        // test the if statement
        if(b3 == "4Band"){
            // if the user has selected a 4 band resistor call the 4 band resistance endpoint
            console.log("It is a 4 band resistor");
            $.get("/4band_resistor", {"b1": b1, "b2": b2, "b4": b4, "b5": b5}, function(response) {
                var data = JSON.parse(response);
                console.log(data);
                $("#Solution").html("<h2> Resistance : " + data["resistance"] +" \u2126" + " </h2><br>" + "<h2> Tolerance: " + data["tolerance"] + "</h2><br>");
            });
        }
        else{
            //  if the user has selected a 5 band resistor call the 5 band resistance endpoint
            $.get("/5band_resistor", {"b1": b1, "b2": b2, "b3": b3, "b4": b4, "b5": b5}, function(response) {
                var data = JSON.parse(response);
                console.log(data);
                $("#Solution").html("<h2> Resistance : " + data["resistance"] +" \u2126" + " </h2><br>" + "<h2> Tolerance: " + data["tolerance"] + "</h2><br>");
            });
        }
    });
});
