@interface LinkedListNode : NSObject {
	NSObject *value;
	LinkedListNode *next;
}

@end

@interface LinkedList : NSObject {
	LinkedListNode *head;
}

@end
