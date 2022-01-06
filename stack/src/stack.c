//
// Created by jsabs on 12/9/21.
//

#include "../include/stack.h"
#include "../include/delete_node.h"
#include "../include/print_node.h"
#include "../include/print_stack.h"

stack_t * init (del_f del_func_t, print_f print_func_t)
{
    if ((NULL == del_func_t) ||
        (NULL == print_func_t))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more function pointer parameters passed are NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    stack_t * stack = calloc(1, sizeof(stack_t));
    if (NULL == stack)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate memory for stack container: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    stack->delete_func = del_func_t;
    stack->print_func  = print_func_t;

    stack->top      = NULL;
    stack->bottom   = NULL;
    stack->size     = 0;

    return stack;
}

/**
 * @brief - a helper function that allocates memory to the heap, creating a stack node container. This node stores the
 *          relevant data passed as well as the appropriate print type function pointer to view the node data.
 * @param data - (void *) a generic pointer to the node data to be stored
 * @param pnode_func_t - (print_n) a function pointer to allow the user to print the data stored within the node
 * @return - (struct node_t *) ON SUCCESS: creates a stack node, storing the appropriate data and print function pointer.
 *           Also sets the initial node index to 0, to be updated during the push function to the appropriate value
 *           along with its next pointer, pointing to the previous node that was at the top of the stack before push was
 *           called. There is one instance in which create_node may fail. If the call to calloc does not operate as
 *           intended, create_node will return a NULL pointer, print a error message to the user and set errno to ENOMEM.
 */
static node_t * create_node (void * data, print_n pnode_func_t)
{
    node_t * node = calloc(1, sizeof(node_t));
    if (NULL == node)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate memory for stack node: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    node->data          = data;
    node->index         = 0;
    node->next          = NULL;
    node->pnode_func    = pnode_func_t;

    return node;
}

/**
 * @brief - this function is an internal helper function meant to appropriate decrease the position member
 *          stored within the queue node container as nodes are removed from the queue container.
 * @param queue - (queue_t *) a pointer to the current queue storage container
 * @return - None. If the queue parameter passed is NULL, errno will be set to EINVAL and an error message
 *           will be sent to STDERR and the decrement functionality will not be performed.
 */
static void decrement_idx (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * current = stack->top;
    while (current)
    {
        current->index--;
        current = current->next;
    }
}

/**
 * @brief - this function is an internal helper function meant to appropriate decrease the position member
 *          stored within the queue node container as nodes are removed from the queue container.
 * @param queue - (queue_t *) a pointer to the current queue storage container
 * @return - None. If the queue parameter passed is NULL, errno will be set to EINVAL and an error message
 *           will be sent to STDERR and the decrement functionality will not be performed.
 */
static void increment_idx (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * current = stack->top->next;
    while (current)
    {
        current->index++;
        current = current->next;
    }
}

int push (stack_t * stack, void * data, print_n pnode_func_t)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data pointer passed is NULL: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    if (NULL == pnode_func_t)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: print node function pointer passed is NULL: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    node_t * new = create_node(data, pnode_func_t);
    if (NULL == new)
    {
        fprintf(stderr, "%s: error occurred create stack node: %s\n",
                __func__, strerror(errno));
        return 1;
    }

    if (NULL == stack->top)
    {
        stack->top      = new;
        stack->bottom   = new;
        new->next       = NULL;
        stack->size++;
    }
    else
    {
        new->next   = stack->top;
        stack->top  = new;
        increment_idx(stack);
        stack->size++;
    }

    return 0;
}

node_t * pop (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    if ((NULL == stack->top) || (0 == stack->size))
    {
        fprintf(stderr, "%s: stack container is currently empty\n",
                                __func__);
        return NULL;
    }

    node_t * current_top = stack->top;
    stack->top = stack->top->next;
    decrement_idx(stack);
    stack->size--;

    return current_top;
}

void peek (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { EMPTY }\n");
    }
    else
    {
        fprintf(stdout, "TOP OF STACK:\n");
        stack->top->pnode_func((void *)stack->top);
    }
}

size_t get_stack_size (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                __func__, strerror(errno));
        return 0;
    }

    if ((NULL == stack->top) || (stack->size == 0))
    {
        return 0;
    }

    return stack->size;
}

void destroy_stack (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        CLEAN(stack);
        return;
    }

    node_t * current   = stack->top;
    node_t * temp      = NULL;
    while (current->next)
    {
        temp    = current;
        current = current->next;
        stack->delete_func(temp);
    }

    stack->delete_func(current);
    stack->top          = NULL;
    stack->bottom       = NULL;
    stack->delete_func  = NULL;
    stack->print_func   = NULL;
    stack->size         = 0;
    CLEAN(stack);
}

/*** end of stack.c ***/