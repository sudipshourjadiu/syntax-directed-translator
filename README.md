# Syntax-Directed Translator with Flex and Bison

**Comiler Desgin Project**

Here is **Syntax-Directed Translator (SDT)** for simple arithmetic expressions **entirely within C code**, without using Flex or Bison. 

However, we would need to manually implement the **lexical analysis**, **parsing**, and **translation logic** in C.

---

## **Approach:**

### **Key Components:**
1. **Lexical Analysis**: Tokenize the input (numbers and operators).
2. **Recursive Descent Parsing**: Parse the input based on grammar rules.
3. **Postfix Translation**: Emit the corresponding postfix notation or assembly-like instructions.

---

## **Grammar for Arithmetic Expressions**
We will use the same grammar:

```
expression → expression + term
           | expression - term
           | term

term → term * factor
     | term / factor
     | factor

factor → NUMBER
       | ( expression )
```

---

## **C Code for the Translator**

Here given the code: (Code)[translator.c]

---

## **Explanation:**
1. **`nextToken()`**: Moves to the next character.
2. **`expression()`**: Handles addition and subtraction.
3. **`term()`**: Handles multiplication and division.
4. **`factor()`**: Handles numbers and parentheses.
5. **Postfix output** is generated as the parse tree is traversed.

---

## **Input and Output Examples:**

| Input Expression   | Postfix Output |
|----------------|-------------------|
| `2 + 3 * 4`          | `2 3 4 * +` |
| `(5 - 2) * 8`       | `5 2 - 8 *` |
| `7 + (6 / 3) * 2` | `7 6 3 / 2 * +` |

---

## **Advantages of this Approach:**
- No dependency on external tools like Flex or Bison.
- Complete control over the logic and error handling.

---

## **Limitations:**
- Harder to extend for more complex grammars.
- Error handling can become more difficult for complex expressions.
