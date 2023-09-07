let n=document.querySelector("input[type=number]")
let button = document.querySelectorAll("input[type=button]")
let output = document.getElementById("output")
for (const btn of button) {
    btn.addEventListener("click", function(){
        output.innerHTML=""
        if(n<=1){
            return
        }
            let a = 1
            let b = 0
            let temp = 0
            let x = 0
            while(x<n.value){
                x++
                temp=a
                a=a+b
                b=temp
                console.log(b)
                output.innerHTML = output.innerHTML + " " + b
        }
        
    })
}