from flask import Flask
app = Flask(__name__)

snake = '''
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Snake</title>
    <style>
        *{
            background-color: blue;
        }
    </style>
</head>
<body>
    <canvas id="gc" width="400" height="400"></canvas>
    <p id="score" style="font-size: 40px;">0</p>
    <script>
        let score = 1;
        let speed = 10;
        window.onload = function() {
            canv = document.getElementById("gc");
            ctx = canv.getContext("2d");
            document.addEventListener("keydown", KeyPush);
            setInterval(game, 1000/speed);
        }
        px=py=10;
        gs=tc=20;
        ax=ay=15;
        xv=yv=0;
        trail=[];
        tail=5;
        function game () {
            px+=xv;
            py+=yv;

            if(px<0) {
                px=tc-1;
            }

            if(px>tc-1) {
                px=0;
            }

            if(py<0) {
                py=tc-1;
            }

            if(py>tc-1) {
                py=0;
            }

            ctx.fillStyle="black";
            ctx.fillRect(0,0,canv.width, canv.height);

            ctx.fillStyle="lime";
            for(var i=0; i<trail.length; i++) {
                ctx.fillRect(trail[i].x*gs, trail[i].y*gs, gs-2, gs-2);
                if(trail[i].x == px && trail[i].y == py) {
                    score = 0;
                    document.getElementById("score").innerHTML = score;    
                    score = 1;
                    tail = 5;
                }
            }
            ctx.fillStyle="red";
            ctx.fillRect(ax*gs, ay*gs, gs-2, gs-2);
            
            trail.push({x:px, y:py});
            while(trail.length>tail){
                trail.shift();
            }
            if(ax==px && ay==py) {
                document.getElementById("score").innerHTML = score;
                score++;
                tail++;
                ax=Math.floor(Math.random()*tc);
                ay=Math.floor(Math.random()*tc);
                // speed = speed + 1;
                // console.log(speed);
                // timer = setInterval(game, 1000/speed);
            }
        }
        function KeyPush (evt) {    
            switch(evt.keyCode) {
                case 37:
                    xv=-1;yv=0;
                    break;
                case 38:
                    xv=0;yv=-1;
                    break;
                case 39:
                    xv=1;yv=0;
                    break;
                case 40:
                    xv=0;yv=1;
                    break;
            }
        }
    </script>
</body>
</html>
'''

@app.route('/game')
def snake_game():
    return snake

@app.route('/hello')
def hello_world():
    return 'Hello TSE!'

@app.route('/goodbye')
def bye():
    return 'bye bye'