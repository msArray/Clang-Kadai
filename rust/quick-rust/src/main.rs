fn partition<T>(slice: &mut [T]) -> Option<usize>
where
    T:Ord,
{
    if slice.len() < 2 {
        return None;
    }

    if slice.len() == 2 {
        if slice[0] > slice[1] {
            slice.swap(0, 1);
        }
        return None;
    }

    let mut p_i = slice.len() - 1;

    let mut i = 0;
    while i < p_i {
        if slice[i] > slice[p_i] {
            slice[i..=p_i].rotate_left(1);
            p_i -= 1;
        } else{
            i += 1;
        }
    }

    Some(p_i)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn can_partition(){
        let mut v = vec![4, -1, 5, -2, 1];

        let pivot_i = partition(&mut v).unwrap();

        assert_eq!(&v[pivot_i], &1);
        assert!(&v[..pivot_i].iter().all(|n| n <= &v[pivot_i]));
        assert!(&v[pivot_i..].iter().all(|n| n >= &v[pivot_i]));
    }

    #[test]
    fn can_finish(){
        let mut v = vec![4, 5];
        let pivot_i = partition(&mut v);

        assert!(pivot_i.is_none());
    }
}

fn recurse<T>(slice: &mut [T], init: usize)
where
    T: Ord,
{
    let lhs = partition(&mut slice[..init]);

    if let Some(i) = lhs {
        recurse(&mut slice[..init], i);
    }

    let rhs = partition(&mut slice[init..]);

    if let Some(i) = rhs {
        recurse(&mut slice[init..], i);
    }
}

fn sort<T>(slice: &mut [T])
where
    T: Ord,
{
    let p_i = partition(slice);

    if let Some(init) = p_i {
        recurse(slice, init);
    }
}

#[cfg(test)]
fn quicksort_works() {
    let mut v = vec![0, -4, 6, 9, -1, 0, 1, 4, 7, 1, -3];

    sort(&mut v);

    assert_eq!(v, vec![-4, -3, -1, 0, 0, 1, 1, 4, 6, 7, 9]);
}

fn main(){
    let mut v = vec![4, -1, 5, -2, 1];
    sort(&mut v);

    for n in v.iter(){
        println!("{}",n);
    }
}