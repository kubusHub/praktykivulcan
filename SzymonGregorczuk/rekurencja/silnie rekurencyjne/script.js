let button = document.querySelectorAll("input[type=button]")
let output = document.querySelector("h1")
function silnia(x){
    if(x>=0){

    
        if (x == 0) {
            return 1;
        }
        else {
            return x * silnia(x - 1);
        }
    }
}
for (const b of button) {
    b.addEventListener("click", function(){
        let nr = document.getElementById("numer").value
        nr = +nr
        console.log(silnia(nr))
    })
}
