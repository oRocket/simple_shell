#include "shell.h"

/**
 * _realloc - Reallocate memory and initialize new values to 0.
 * @ptr: Pointer to the memory previously allocated (malloc(old_size)).
 * @old_size: Size previously allocated.
 * @new_size: New size for reallocation.
 *
 * Return: Pointer to reallocated memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;
    unsigned int i = 0;

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr); /* Free memory if reallocating to size 0. */
        return (NULL);
    }

    if (new_size == old_size)
        return (ptr); /* Return ptr if reallocating to the same old size. */

    if (ptr == NULL)
    {
        new_ptr = malloc(new_size); /* Malloc new size if ptr is originally NULL. */
        if (new_ptr == NULL)
            return (NULL);
        else
            return (new_ptr);
    }

    new_ptr = malloc(new_size); /* Malloc and check for errors. */
    if (new_ptr == NULL)
        return (NULL);

    /* Copy values up to the minimum of old or new size. */
    while (i < old_size && i < new_size)
    {
        *((char *)new_ptr + i) = *((char *)ptr + i);
        i++;
    }

    free(ptr); /* Free the old ptr. */

    return (new_ptr);
}
