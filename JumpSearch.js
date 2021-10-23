function jumpSearch(arr, item) {
    let len = arr.length;
    let step = Math.floor(Math.sqrt(len)); // each block size is sqrt(array length)
    let currentStep = step;
    let start = 0;

    while(arr[Math.min(currentStep, len) - 1] < item) {
        // jump to next block
        start = currentStep;
        currentStep += step;
        // element does not exists if starts exceeds the length of the array
        if(start >= len) {
            return -1;
        }
    }
    // linear search to find the item in the block
    while(arr[start] < item) {
        start++;
        // element does not exists if starts exceeds the block size
        if(start == Math.min(currentStep, len)) {
            return -1;
        }
    }
    if(arr[start] == item) {
        // element found and index returned
        return start;
      } else {
        // element not found
        return -1;
    }
}
// Sorted input array
let arr = [11,23,34,56,62,78,99,103,117,143,158,171,189,191,200];

console.log("Element Found At Index " + jumpSearch(arr, 158));
console.log("Element Found At Index " + jumpSearch(arr, 65));
console.log("Element Found At Index " + jumpSearch(arr, 62));
