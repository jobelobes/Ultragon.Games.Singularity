void RotateCallback(Behavior* sender, float elapsedTime)
{
	Transform* transform = sender->Get_GameObject()->Get_Transform();
	transform->Rotate(0, D3DX_PI * 1.0f * elapsedTime, 0);
}

void TranslateCallback(Behavior* sender, float elapsedTime)
{
	Transform* transform = sender->Get_GameObject()->Get_Transform();
	transform->Rotate(0, D3DX_PI * 2.0f * elapsedTime, 0);
}

void UT_GameObjectAllocation()
{
	unsigned max = 1024;
	GameObject** objects = new GameObject*[max];
	
	printf("UT_GameObjectAllocation Executing...\n");

	printf("\tCreating GameObjects...");
	for(int i = 0; i < max; ++i)
		objects[i] = GameObject::Create();
	printf("Done\n");

	printf("\tDestroying GameObjects...");
	for(int i = 0; i < max; ++i)
		objects[i]->Destroy();
	printf("Done\n");
	
	printf("Done\n");
}

void UT_TransformParenting()
{
	printf("UT_TransformParenting Executing...\n");

	Behavior* rotateBehavior = new Behavior();
	rotateBehavior->Update.Add(new BehaviorDelegate(RotateCallback));
	Behavior* translateBehavior = new Behavior();
	translateBehavior->Update.Add(new BehaviorDelegate(TranslateCallback));

	GameObject* root = GameObject::Create();
	root->AddComponent(rotateBehavior);
	root->AddComponent(new MeshRenderer(Mesh::CreatePrimitive(PrimitiveType::Cube), Material::CreateBasicMaterial()));
	root = GameObject::Create("", root);
	root->Get_Transform()->Translate(6, 0, 0);
	root->AddComponent(translateBehavior);
	root->AddComponent(new MeshRenderer(Mesh::CreatePrimitive(PrimitiveType::Cube), Material::CreateBasicMaterial()));
	root = GameObject::Create("", root);
	root->Get_Transform()->Translate(3, 0, 0);
	root->AddComponent(new MeshRenderer(Mesh::CreatePrimitive(PrimitiveType::Cube), Material::CreateBasicMaterial()));
	
	printf("Done\n");
}