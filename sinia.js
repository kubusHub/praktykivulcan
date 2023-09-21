function sinia(num) {
    var wynik = num;
    if (num === 0 || num === 1) 
      return 1; 
    while (num > 1) { 
      num--;
      wynik *= num;
    }
    return wynik;
  }
  sinia(5);



const number = parseInt(prompt('numer pofturzeni'));
let n1 = 0, n2 = 1, nastempny;

console.log('ciong fibonaciego');

for (let i = 1; i <= number; i++) {
    console.log(n1);
    nastempny = n1 + n2;
    n1 = n2;
    n2 = nastempny;
}