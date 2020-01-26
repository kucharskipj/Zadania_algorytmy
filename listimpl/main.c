#include "list.h"

int main(void) {
    List * list = create_list();
    append_to_list(list,101);
    count_elements(list);
    get_nth_element(list,0);
    insert_to_list(list,101,0);
    clear_list(list);
    remove_nth_element(list, 2);
    destroy_list(&list);
}


