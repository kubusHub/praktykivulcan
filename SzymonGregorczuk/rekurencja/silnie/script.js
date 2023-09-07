let button = document.querySelectorAll(".btn")
for (const b of button) {
    b.addEventListener("click", function(){
        let output=document.getElementById("output")
        let n = document.getElementById("nr")
        console.log(Number(n.value))
        n = Number(n.value)
        if(n<0){
            output.innerHTML= "podaj liczbe naturalną wiekszą niż zero!!!"
            return
        }
        let x = 0
        let eq = 1
        while(x<n){
            x++
            eq=eq * (1 * x)
        }
        output.innerHTML= n+"!"+" = "+eq
    })
}
