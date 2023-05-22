const array = [-5,3,4,2,-7,-2,7];
let count = 0;
const pplus =[];
const mminus =[];


array.forEach((element) =>{
    if(element>0){
        pplus.push(element);
    }
    else if(element<0){
        mminus.push(element);
    }
})

console.log(pplus);
console.log(mminus);