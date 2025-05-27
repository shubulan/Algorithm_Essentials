
use std::io;
use std::str::FromStr;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let v:Vec<&str> = input.split_ascii_whitespace().collect();
    let a = i32::from_str(v[0]).unwrap();
    let b = i32::from_str(v[1]).unwrap();
    println!("{}", a * b);

}