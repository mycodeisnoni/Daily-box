const arr =[1,2,3,4,5,6,7,8,9,10]

arr1 = arr.filter(e=> e%2===0)
console.log(arr1.map(e=>e*10))



const arr2 = [1,2,3,4,5,6,7,8,9,10]
arr.reduce((acc,cur)=>{
    if(cur%2===0){
        acc[cur] = acc[cur] + cur*10;
    }
    return acc;
},[])