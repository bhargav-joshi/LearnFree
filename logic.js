document.querySelector("button").addEventListener("click",randomd)
function randomd(){
    var x = Math.random();
    x=x*90;
    var y= Math.floor(x)+1;
    document.querySelectorAll("h1")[1].innerHTML=y;
}