file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/CustomerRepository.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

action parameters:
uri: file:///C:/Users/viole/Desktop/ERASMUS/CPS2004-OOP/application/src/main/java/project/customer/CustomerRepository.java
text:
```scala
package project.customer;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class CustomerRepository {
    private static List<Customer> repository;
    private static int nextIdCustomer;

    public CustomerRepository() {
        this.repository = new ArrayList<Customer>();
        this.nextIdCustomer = 1;
    }

    public int nextIdCustomer() {
        return this.nextIdCustomer++;
    }

    public  void saveCustomer(Customer customer) {
        repository.add(customer);
    }

    public void updateCustomer(int id,String change) {
        if (!repository.contains(repository.get(id))) {
            throw new IllegalAccessError ("Customer not found");
        }
        Customer customer = repository.get(id);
        customer.updateCustomer(change);
    }

    public Customer getCustomerById(int id) {
        return this.repository.get(id);
    }

    public Customer getCustomerByName(String name) {
        for (Customer customer : repository) {
            if (customer.getName().equals(name)) {
                return customer;
            }
        }
        return null;
    }

    public List<Customer> getAllCustomers() {
        for
    }

    public void deleteCustomer(Customer customer) {
        repository.remove(customer);
    }
    //todo get this fixed
}

```



#### Error stacktrace:

```
scala.collection.Iterator$$anon$19.next(Iterator.scala:973)
	scala.collection.Iterator$$anon$19.next(Iterator.scala:971)
	scala.collection.mutable.MutationTracker$CheckedIterator.next(MutationTracker.scala:76)
	scala.collection.IterableOps.head(Iterable.scala:222)
	scala.collection.IterableOps.head$(Iterable.scala:222)
	scala.collection.AbstractIterable.head(Iterable.scala:933)
	dotty.tools.dotc.interactive.InteractiveDriver.run(InteractiveDriver.scala:168)
	scala.meta.internal.pc.MetalsDriver.run(MetalsDriver.scala:45)
	scala.meta.internal.pc.PcCollector.<init>(PcCollector.scala:45)
	scala.meta.internal.pc.PcSemanticTokensProvider$Collector$.<init>(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector$lzyINIT1(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.Collector(PcSemanticTokensProvider.scala:61)
	scala.meta.internal.pc.PcSemanticTokensProvider.provide(PcSemanticTokensProvider.scala:90)
	scala.meta.internal.pc.ScalaPresentationCompiler.semanticTokens$$anonfun$1(ScalaPresentationCompiler.scala:99)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator