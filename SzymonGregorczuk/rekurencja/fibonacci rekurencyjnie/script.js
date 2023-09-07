let output = document.getElementById('output')
let nr = document.querySelector('input[type=number]')
let button = document.querySelectorAll('input[type=button]')
for (const btn of button) {
    btn.addEventListener("click", function(){
        output.innerHTML = ""
        for(i=0; i<nr.value; i++){
            output.innerHTML = `${output.innerHTML} ${fibonacci(i)}`
        }
        
    })
}
function fibonacci(n){
    if(n<=0){
        return 0
    }
    else if(n===1){
        return 1
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2)
    }
}
