/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:12:39 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/01/13 12:19:17 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void    ft_swap(int *a, int *b){
//     int tmp;
//     tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int pivot_adjuster(int *tab, int start, int end){
//     int pivot = tab[end];
//     int i = start - 1;
//     int j = start;
//     while (j < end){
//         if (tab[j] < pivot){
//             i++;
//             ft_swap(&tab[i], &tab[j]);
//         }
//         j++;
//     }
//     ft_swap(&tab[i + 1], &tab[end]);
//     return (i + 1);
// }

// void    quick_sort(int *tab, int start, int end){
//     if (start < end){
//         int pivot = pivot_adjuster(tab, start, end);
//         quick_sort(tab, start, (pivot - 1));
//         quick_sort(tab, (pivot + 1), end);   
//     }
// }


// void sort_int_tab(int *tab, unsigned int size){
//     quick_sort(tab, 0, size - 1);
// }

void sort_int_tab(int *tab, unsigned int size){
    int i = 0;
    int tmp = 0;
    while (i < size-1){
        if (tab[i] > tab[i + 1]){
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
}

// #include <libc.h>
// int main(){
//     int tab[6] = {3, 2, 1, 5, 6, 4};
//     sort_int_tab(tab, 6);
//     int i = 0;
//     while (i < 6){
//         printf("%d", tab[i]);
//         i++;
//     }
//     return 0;
// }