use std::io;

fn main() {

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input = input.trim().to_string();
    unsafe {
        input.as_mut_vec().reverse();
    }
    println!("{}", input);

}