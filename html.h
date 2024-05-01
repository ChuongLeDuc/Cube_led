const char index_page[] PROGMEM = R"=====(
  <!DOCTYPE html>
<head>
    <title>ANIMATION CONTROL</title>

    <style>

        #main_div{
            background: #d5e6f5;
            width: 50%;
            height: 330px;
            text-align: center;
            margin: 50px auto;
        }
        button{
            margin: 10px auto;
            height: 90px;
            width: 170px;
            border: none;
            border-radius: 10px;
            color: #3d2f54;
            font-weight: 600;
            font-family: serif;
        }
        body{
            background:#d5e6f5;
        }
    </style>
</head>

<body>
    <div id="main_div">
        <button onclick="animation(1)" style="background:#3bffae">SQUARE LEFT RIGHT</button>
        <button onclick="animation(2)" style="background:#3bffae">SQUARE UP DOWN</button>
        <button onclick="animation(3)" style="background:#3bffae">SQUARE FRONT BACK</button>
        
        <button onclick="animation(4)" style="background: #73dbe5;">CYCLE</button>
        <button onclick="animation(5)" style="background: #73dbe5;">LIGHT RANDOM</button>
        <button onclick="animation(6)" style="background: #73dbe5;">RAIN</button>
    
        <button onclick="animation(7)" style="background: #f79a85;">WAVE</button>
        <button onclick="animation(8)" style="background: #f79a85;">DISPLAY TEXT</button>
        <button onclick="animation(9)" style="background: #f79a85;">DYNAMIC</button>

        
        <button onclick="animation(10)" style="background: #0dabe7;">CUBE EXPANDING</button>
        <button onclick="animation(11)" style="background: #0dabe7;">MINI CUBE</button>
        <button onclick="animation(12)" style="background: #0dabe7;">X MOVING</button>

        <button onclick="animation(13)" style="background: #0dabe7;">SQUARE BLINK</button>


        <p id="current_animation"></p>
    </div>

    <script>
        function animation(a){

            var xhttp=new XMLHttpRequest;
                xhttp.open("GET","/animation?animation_name="+a,true);
                //console.log("/device_wifi?device_name="+device_name.value+"&old_pass="+old_pass.value+"&new_pass="+new_pass.value);
                xhttp.onreadystatechange=function(){
                    if (this.readyState == 4 && this.status == 200) {
                        var respone=xhttp.responseText;
                        console.log(respone);
                        document.getElementById("current_animation").innerHTML=respone;
                    }else{
                      console.log(this.readyState);
                      console.log("    ");
                      console.log(this.status);
                    }
                }
                xhttp.send();
        }
    </script>
</body>
)=====";
