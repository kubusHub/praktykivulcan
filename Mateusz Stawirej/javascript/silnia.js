function sil(){
    let x = 0
    result = 1
    si = document.getElementById('si').value
    while (si >0){
        x++
        result=result * x
        si = si - 1;
    }
    console.log(result)
}

// TU JEST CIAG FIBONACZIEGO
let button = document.querySelectorAll("input[type=button]")
let num = document.querySelectorAll("input[type=number]")
let odp = document.querySelectorAll("p")

for(const g of button){
    g.addEventListener("click",function(){
    for(let i=0;i<num.value;i++){
        console.log(fib(i))
    
}

    })
}
function fib(n){
    if(n<=0){
        return 0
    }
    else if(n===1){
        return 1
       
    }
    else{
        console.log(fib(n-1) + fib(n-2))
    }
}



