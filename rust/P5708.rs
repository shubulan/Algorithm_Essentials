

use std::io;
use std::str::FromStr;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input = input.trim().to_string();

    let v: Vec<&str> = input.split_ascii_whitespace().collect();
    let v: Vec<f64> = v.into_iter().map(|x| f64::from_str(x).unwrap()).collect();
    let (a, b, c) = (v[0], v[1], v[2]);
    let p = (a + b + c) / 2.0;
    println!("{:.1}", f64::sqrt(p * (p - a)*(p - b)*(p - c)));

}