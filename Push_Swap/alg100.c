#include "push_swap.h"

void    alg_100(t_stack *s)
{
    indexing(s);
    markup_bool(s);
    pushtob(s);
    replace_a(s);
    findtheplace(s);
    legacy(s);
    replace_a(s);

}

void replace_a(t_stack *s)
{
    trueindexingA(s);
    int min_a = find_min_true_a(s);
    while(min_a > 0)
    {
        // printf("stex\n");
        rotate(&s->a);
        write(1, "ra\n", 3);
        min_a--;
    }
        int i = 0;
    while(i < s->size_a)
	{
		// printf("INITIAL A:%d ->true index  %d, -> index  %d, markup result->  %d\n", s->a->data, s->a->true_index, s->a->index, s->a->mp_result);
    	s->a = s->a->next;
	    i++;
	}

}

void        find_size(t_stack *s, int b_item, int a_item)
{
    s->b->ss = 0;
    s->b->rr = 0;
    s->b->ra = 0;
    s->b->rb = 0;
    s->b->rrr = 0;
    s->b->rra = 0;
    s->b->rrb = 0;

    int size_indeed_a = s->size_a;
    int size_indeed_b = s->size_b;

    if(size_indeed_a % 2 == 1)
        size_indeed_a++;
    if(size_indeed_b % 2 == 1)
        size_indeed_b++;

    if(s->size_b/2 > b_item && s->size_a/2 > a_item)
    {
        // printf("a %d b %d |1|\n", a_item, b_item);
        if (a_item > b_item)
        {
            s->b->count_of_b = a_item +1;
            s->b->rr = b_item;
            s->b->ra = a_item - b_item;
            // printf("rr %d\n", s->b->rr);
            // printf("ra %d\n", s->b->ra);
        }
        else
        {
            s->b->count_of_b = b_item + 1;
            s->b->rr = a_item;
            // printf("rr %d\n", s->b->rr);
            s->b->rb = b_item - a_item;
            // printf("rb %d\n", s->b->rb);
        }
    }
    else if(s->size_b/2 <= b_item && s->size_a/2 <= a_item)
    {
        // printf("a %d b %d |2|\n", a_item, b_item);
        int size_a = s->size_a - a_item;
        int size_b = s->size_b - b_item;
        if(size_a > size_b)
        {
            s->b->count_of_b = size_a + 1;
            s->b->rrr = size_b;
            s->b->rra = size_a - size_b;
            // printf("rrr %d\n", s->b->rrr);
            // printf("rra %d\n", s->b->rra);
        }
        else
        {
            s->b->count_of_b = size_b + 1;
            s->b->rrr = size_a;
            s->b->rrb = size_b - size_a;
            // printf("rrr %d\n", s->b->rrr);
            // printf("rrb %d\n", s->b->rrb);
        }
    }
    else if(s->size_b/2 > b_item && s->size_a/2 <= a_item)
    {
        // printf("a %d b %d |3|\n", a_item, b_item);
        s->b->count_of_b = s->size_a - a_item +  1 + b_item;
        s->b->rb = b_item;
        s->b->rra = s->size_a - a_item;
        // printf("rb %d\n", s->b->rb);
        // printf("rra %d\n", s->b->rra);
    }
    else if(s->size_b/2 <= b_item && s->size_a/2 > a_item)
    {
        // printf("a %d b %d |4|\n", a_item, b_item);
        s->b->count_of_b = s->size_b - b_item + a_item + 1;
        s->b->ra = a_item;
        s->b->rrb = s->size_b - b_item;
        // printf("|rrb| %d\n", s->b->rrb);
        // printf("rb %d\n", s->b->rb);
    }
}

int       findtheplace(t_stack *s)
{
    // printf("STE EL\n");
    if(is_sorted(s) && s->size_b == 0)
        return 0;
    // replace_a(s);
    trueindexingB(s);
    trueindexingA(s);
    int i = 0;
    int j = 0;
    int min_true;
    int move_item;
    int max_true;

    int min_el = find_min_a(s);
    int max_el = find_max_a(s);

    while(i < s->size_b)
    {
        if(s->b->index < min_el)
        {
            move_item = s->b->true_index;
            min_true = find_min_true_a(s);
            // printf("true min:%d\n", min_true);
            find_size(s, move_item, min_true);
        }
        else if (s->b->index > max_el)
        {
            move_item = s->b->true_index;
            max_true = find_max_true_a(s);
            // printf("true max:%d\n", max_true);
            find_size(s, move_item, max_true);
        }
        else
        {
            int garnik = 0;
            j = 0;
            int a_true = 0;
            int a_index = 0;
            while (j < s->size_a)
            {
                if(garnik == 0 && s->a->index > s->b->index)
                {
                    a_index = s->a->index;
                    a_true = s->a->true_index;
                    garnik++;
                }
                if(a_index > s->a->index && s->a->index > s->b->index && garnik)
                {
                    a_true = s->a->true_index;
                    a_index = s->a->index;
                }
                ++j;
                s->a = s->a->next;
            }
            j = 0;
            garnik = 0;
            move_item = s->b->true_index;
            s->b->ayitexe = a_true;
            find_size(s, move_item, a_true);
        }
    s->b = s->b->next;
    i++;
    }
    return 0;
}

void doFunctions(int minimum, t_stack *s, int j, t_commands *commands)
{
        // int k = 0;

	    // while(k < s->size_b)
	    // {
	    // 	printf("B:%d ->true index  %d, -> index  %d, markup result->  %d - > count of b %d\n", s->b->data, s->b->true_index, s->b->index, s->b->mp_result, s->b->count_of_b);
        // 	s->b = s->b->next;
	    //     k++;
	    // }
    j = 0;
    minimum = 0;
    if(commands->rrr)
    {
        while(commands->rrr > 0)
        {
            rrr(s);
            write(1, "rrr\n", 4);
           commands->rrr--;
        }
    }
    if(commands->rr)
    {
        while(commands->rr > 0)
        {
            rr(s);
            write(1, "rr\n", 3);
           commands->rr--;
        }
    }
    if(commands->ra)
    {
        while(commands->ra > 0)
        {
            rotate(&s->a);
            write(1, "ra\n", 3);
           commands->ra--;
        }
    }
    if(commands->rb)
    {
        while(commands->rb > 0)
        {
           rotate(&s->b);
           write(1, "rb\n", 3);
           commands->rb--;
        }
    }
    if(commands->rra)
    {
        while(commands->rra > 0)
        {
            rrotate(&s->a);
            write(1, "rra\n", 4);
            commands->rra--;
        }
    }
    if(commands->rrb)
    {
        while(commands->rrb > 0)
        {
            rrotate(&s->b);
            write(1, "rrb\n", 4);
           commands->rrb--;
        }
    }

    // if(j != 1)
    pa(s);
    write(1, "pa\n", 3);
    // if(j != 1)
    findtheplace(s);
    // replace_a(s);
}

void        legacy(t_stack *s)
{
    t_commands commands;
    int minimum = 0;
    int i = 0;
    int j = 0;
    int s_size = s->size_b;

    while(j < s_size){
        while(i < s->size_b)
        {
            if(!i)
            {
                minimum = s->b->count_of_b;
                commands.ra = s->b->ra;
                commands.rb = s->b->rb;
                commands.rra = s->b->rra;
                commands.rrb = s->b->rrb;
                commands.rr = s->b->rr;
                commands.rrr = s->b->rrr;
            }
            if(minimum > s->b->count_of_b)
            {
                minimum = s->b->count_of_b;
                commands.ra = s->b->ra;
                commands.rb = s->b->rb;
                commands.rra = s->b->rra;
                commands.rrb = s->b->rrb;
                commands.rr = s->b->rr;
                commands.rrr = s->b->rrr;
            }
            s->b = s->b->next;
            i++;
        }
        i = 0;
        doFunctions(minimum, s, j, &commands);
        j++;
    }
}

int        there_is_false(t_stack *s)
{
    int i;
    t_list *list;
    list = s->a;
    i = 0;
    while (i < s->size_a)
    {
        if (list->mp_result == 0)
            return 1;
        ++i;
        list = list->next;
    }
    return 0;
}

// int         sa_is_needed(t_stack *s)
// {
//     // printf("s->a->counnt:%d\n", s->a->count);
//     t_list  *list;
//     list = s->a;
//     int tmp_count = list->count;
//     // printf("before%d\n", tmp_count);
//     swap(list);
//     // printf("after swap\n");
//     markup_bool(s);

//     // printf("after%d\n", list->count);
//     swap(list);
//     // printf("swap back\n");
//     if(tmp_count < list->count)
//         return 1;
//     else
//         return 0;
// }

void        pushtob(t_stack *s)
{

    while (there_is_false(s))
    {
        // if(sa_is_needed(s))
        // {
        //     swap(s->a);
        //     write(1, "sa\n", 3);
        //     // markup_bool(s);
        // }
        if(s->a->mp_result == false)
        {
            pb(s);
            write(1, "pb\n", 3);
        }
        else
        {
            rotate(&s->a);
            write(1, "ra\n", 3);
        }


    }
        int i = 0;
    while(i < s->size_a)
	{
		// printf("INITIAL A:%d ->true index  %d, -> index  %d, markup result->  %d\n", s->a->data, s->a->true_index, s->a->index, s->a->mp_result);
    	s->a = s->a->next;
	    i++;
	}
    	i = 0;
	while(i < s->size_b)
	{
		// printf("B:%d ->true index  %d, -> index  %d, markup result->  %d - > count of b %d\n", s->b->data, s->b->true_index, s->b->index, s->b->mp_result, s->b->count_of_b);
    	s->b = s->b->next;
	    i++;
	}
    // printf("|||%d|||", s->a->data);
}