let button = document.querySelectorAll("input[type=button]")
let nr = document.getElementById("numer")
nr = Number(nr.value)
console.log(nr.value)
let output = document.querySelector("h1")
function silnia(n){
    if(n<0){
        return
    }
    else{
        let wynik = n * silnia(n-1)
    }
}
for (const b of button) {
    b.addEventListener("click", function(){
        silnia(nr.value)
        console.log(wynik)
    })
}