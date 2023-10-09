// A Rust implementation of fibonacci sequence
// Read value from stdin and print fibonacci sequence
use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input);
    let mut a = 0;
    let mut b = 1;
    let mut c = 0;
    let mut i = 0;
    while i < input.trim().parse::<i32>().unwrap() {
        println!("{}", a);
        c = a + b;
        a = b;
        b = c;
        i += 1;
    }
}