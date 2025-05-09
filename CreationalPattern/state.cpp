#include <iostream>

class DocumentContext;
class DocumentState
{
public:
	virtual void edit(DocumentContext* doc) = 0;
	virtual void review(DocumentContext* doc) = 0;
	virtual void publish(DocumentContext* doc) = 0;
	virtual ~DocumentState() {}
};

class DocumentContext
{
	DocumentState* state;
public:
	DocumentContext(DocumentState* init) : state(init) {}
	~DocumentContext() { delete state; }
	void setState(DocumentState* newState) {
		delete state;
		state = newState;
	}

	void edit()
	{
		state->edit(this);
	}
	void review() {
		state->review(this);
	}
	void publish()
	{
		state->publish(this);
	}
};

// state concrete classes
class DraftState : public DocumentState
{
public:
	void edit(DocumentContext* doc) override;
	void review(DocumentContext* doc) override;
	void publish(DocumentContext* doc) override;
};

class ModerationState : public DocumentState
{
public:
	void edit(DocumentContext* doc) override;
	void review(DocumentContext* doc) override;
	void publish(DocumentContext* doc) override;
};

class PublishedState : public DocumentState
{
public:
	void edit(DocumentContext* doc) override;
	void review(DocumentContext* doc) override;
	void publish(DocumentContext* doc) override;
};

void DraftState::edit(DocumentContext* doc){
	std::cout << "editing doc. in draft mode \n";
}
void DraftState::review(DocumentContext* doc){
	std::cout << "moving doc. to the moderation \n";
	doc->setState(new ModerationState());
		// setState - DocumentState*
}
void DraftState::publish(DocumentContext* doc){
	std::cout << "cant publish directly from draft \n";
}



void ModerationState::edit(DocumentContext* doc)  {
	std::cout << "can't edit in moderation, sending back to draft mode \n";
	doc->setState(new DraftState());
}
void ModerationState::review(DocumentContext* doc)  {
	std::cout << "already in moderation \n";
}
void ModerationState::publish(DocumentContext* doc)  {
	std::cout << "publishing doc. \n";
	doc->setState(new PublishedState());
}



void PublishedState::edit(DocumentContext* doc)  {
	std::cout << "can't eidt a published doc. \n";
}
void PublishedState::review(DocumentContext* doc)  {
	std::cout << "already published, no need to review \n";
}
void PublishedState::publish(DocumentContext* doc) {
	std::cout << "doc. is already published \n";
}

int main()
{
	DocumentContext doc(new DraftState());
	doc.edit();
	doc.publish();
	doc.review();
	doc.publish();
	doc.publish();

	return 0;
}